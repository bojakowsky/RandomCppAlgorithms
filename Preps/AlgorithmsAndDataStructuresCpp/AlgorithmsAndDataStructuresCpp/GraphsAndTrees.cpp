#include "GraphsAndTrees.h"
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
namespace graphsAndTrees {
	//Binary search tree node
	class BstNode
	{
	public:
		BstNode() {
			this->left = nullptr;
			this->right = nullptr;
		}

		BstNode(int data)
		{
			BstNode();
			this->data = data;
		}

		BstNode* createNode(int data = 0) {
			return new BstNode(data);
		}

		int data;
		BstNode *left;
		BstNode *right;

		//Added in task 6
		BstNode *parent = nullptr;
	};

	//Task 7
	static class Result
	{
	public:
		BstNode *node;
		bool isAncestor;
		Result(BstNode *n, bool isAnc)
		{
			node = n;
			isAncestor = isAnc;
		}
	};

	template <class T>
	class LinkedListNode
	{
	public:
		LinkedListNode() {
			this->next = nullptr;
		}

		LinkedListNode(T data)
		{
			LinkedListNode();
			this->data = data;
		}

		T data;
		LinkedListNode *next;
	};


	template <class T>
	class LinkedLists
	{
	private:
		std::vector<BstNode*> iterator;
	public:
		LinkedListNode<T>* root = nullptr;

		void clear()
		{
			while (root != nullptr)
			{
				LinkedListNode<T>* next = root->next;
				delete root;
				root = next;
			}
		}

		int size()
		{
			if (root == nullptr)
				return 0;

			int size = 0;
			LinkedListNode<T>* runner = root;

			while (runner != nullptr)
			{
				++size;
				runner = runner->next;
			}

			return size;
		}

		void append(T data)
		{
			if (root == nullptr)
				root = new LinkedListNode<T>(data);
			else {
				LinkedListNode<T> *n = root;
				while (n->next != nullptr)
					n = n->next;
				n->next = new LinkedListNode<T>(data);
			}
		}

		void insertBegin(T data)
		{
			if (root == nullptr)
				root = new LinkedListNode<T>(data);
			else {
				LinkedListNode *n = new LinkedListNode<T>(data);
				n->next = root;
				root = n;
			}
		}
	};

	//Binary search tree
	class Bst {
	public:
		BstNode *root = nullptr;

		bool containsTree2(BstNode *t1, BstNode *t2) {
			//TODO in future, meaby
		}

		bool containsTree(BstNode *t1, BstNode *t2)
		{
			//The emtpy tree is always a sbutree
			if (t2 == nullptr) 
				return true;
			return subTree(t1, t2);
		}

		bool subTree(BstNode *r1, BstNode *r2)
		{
			if (r1 == nullptr)
				return false; //big tree is empty & in subtree not found yet.

			if (r1->data == r2->data)
			{
				if (matchTree(r1, r2)) return true;
			}

			return (subTree(r1->left, r2) || subTree(r1->right, r2));
		}

		bool matchTree(BstNode *r1, BstNode *r2)
		{
			if (r1 == nullptr && r2 == nullptr)
				return true; //nothing left, thus no difference has been found

			if (r1 == nullptr || r2 == nullptr)
				return false; //one is not null, so there's difference in number of nodes

			if (r1->data != r2->data)
				return false; // if data is different, then subtree is obviously not equal
			else
				return (matchTree(r1->left, r2->left) 
					&& matchTree(r1->right, r2->right));

		}

		Result *commonAncestorHelper(BstNode *root, BstNode *p, BstNode *q)
		{
			if (root == nullptr) return new Result(nullptr, false);
			if (root == p && root == q) return new Result(root, true);

			Result *rx = commonAncestorHelper(root->left, p, q);
			if (rx->isAncestor)
				return rx;

			Result *ry = commonAncestorHelper(root->right, p, q);
			if (ry->isAncestor)
				return ry;

			if (rx->node != nullptr && ry->node != nullptr)
				return new Result(root, true);
			else if (root == q || root == p)
			{
				bool anc = rx->node != nullptr || ry->node != nullptr ? true : false;
				return new Result(root, anc);
			}
			else
				return new Result(rx->node != nullptr ? rx->node : ry->node, false);

		}

		BstNode *commonAncestor(BstNode *root, BstNode *p, BstNode *q)
		{
			Result *r = commonAncestorHelper(root, p, q);
			if (r->isAncestor)
				return r->node;
			return nullptr;
		}

		BstNode* insert(BstNode* node, int data)
		{
			if (node == nullptr) {
				node = node->createNode(data);
			}


			//in BST trees all children's data values are less or equal to the actual node. 
			//Thus all children on right have data values greater than the actual node.
			else if (data <= node->data)
			{
				node->left = insert(node->left, data);

				//Added in task 6
				node->left->parent = node;
			}
			else
			{
				node->right = insert(node->right, data);

				//Added in task 6
				node->right->parent = node;
			}

			return node;
		}

		void print_preorder(BstNode* node)
		{
			if (node == nullptr)
				return;
			else {
				std::cout << node->data << std::endl;
				print_preorder(node->left);
				print_preorder(node->right);
				
			}
		}

		void print_inorder(BstNode* node)
		{
			if (node == nullptr)
				return;
			else {
				print_inorder(node->left);
				std::cout << node->data << std::endl;
				print_inorder(node->right);

			}
		}

		void print_postorder(BstNode* node)
		{
			if (node == nullptr)
				return;
			else {
				print_postorder(node->left);
				print_postorder(node->right);
				std::cout << node->data << std::endl;

			}
		}

		void print_breadthFirstOrder(BstNode *node)
		{
			//BFS for trees is nothing more than level order!
			print_levelOrder(node);
		}

		void print_depthFirstOrder(BstNode *node)
		{
			//DFS for trees : inorder, postorder, preorder, they're good enough for depth first order
		}

		void print_preorderToHeight(BstNode *node, int heigth)
		{
			if (heigth == -1 || node == nullptr) return;

			std::cout << (node->data) << std::endl;
			print_preorderToHeight(node->left, heigth - 1);
			print_preorderToHeight(node->right, heigth - 1);

		}

		bool search(BstNode *node, int data)
		{
			if (node == nullptr) return false;
			else if (node->data == data) return true;
			else if (data < node->data) search(node->left, data);
			else search(node->right, data);
		}

		void print_levelOrder(BstNode *node)
		{
			if (node == nullptr) return;
			std::queue<BstNode*> q;
			q.push(node);
			while (!q.empty())
			{
				BstNode *current = q.front();
				std::cout << current->data << std::endl;
				if (current->left != nullptr) q.push(current->left);
				if (current->right != nullptr) q.push(current->right);

				q.pop();
			}
		}

		//// It can be done better
		int treeHeight_SLOW(BstNode *n)
		{
			if (n == nullptr) return 0;

			return std::max(treeHeight_SLOW(n->left), treeHeight_SLOW(n->right)) + 1;
		}

		//Balanced tree, is such a tree, that difference in height of subtrees of that tree is not more than X (1 in that special case)
		bool isTreeBalanced_SLOW(BstNode *node) // O(N^2)
		{
			if (node == nullptr) return true;
			
			int diff = std::abs(treeHeight_SLOW(node->left) - treeHeight_SLOW(node->right));
			if (diff > 1)
				return false;
			else {
				return isTreeBalanced_SLOW(node->left) && isTreeBalanced_SLOW(node->right);
			}
		}

		int checkHeight(BstNode *node)
		{
			if (node == nullptr)
			{
				//Height of 0
				return 0;
			}

			//Check if left is balanced
			int leftHeight = checkHeight(node->left);
			if (leftHeight == -1)
				return -1; // not balanced

			int rightHeight = checkHeight(node->right);
			if (rightHeight == -1)
				return -1; // also not balanced

			//Check current node
			int diff = std::abs(leftHeight - rightHeight);
			if (diff > 1)
				return -1; //not balanced
			else
			{
				//return the heigth
				//std::cout << std::max(leftHeight, rightHeight) + 1;
				return std::max(leftHeight, rightHeight) + 1;
			}

		}

		int getMax(BstNode *node)
		{
			//Algorithm approach is analogous to getMin function
			if (node == nullptr)
				return -1; 
			else if (node->right == nullptr)
				return node->data; 
			return getMax(node->right);
		}

		int getMin(BstNode *node)
		{
			if (node == nullptr)
				return -1; // tree is null
			else if (node->left == nullptr)
				return node->data; // this node is the smallest node

			//Search in left subtree, because in bst, lowest value will be on the very left
			return getMin(node->left);
		}

		BstNode* getMinNode(BstNode *node)
		{
			if (node == nullptr)
				return node;

			else if (node->left == nullptr)
				return node;

			return getMinNode(node->left);
		}

		bool isTreeBalanced(BstNode *node) //O(N) time, and O(H - tree height) space
		{
			if (checkHeight(node) == -1)
				return false;
			return true;
		}


		bool isLeftSubtreeLesserOrEqual_HEAVY(BstNode *node, int value)
		{
			if (node == nullptr) return true;
			if (node->data <= value
				&& isLeftSubtreeLesserOrEqual_HEAVY(node->left, value)
				&& isLeftSubtreeLesserOrEqual_HEAVY(node->right, value))
				return true;
			else return false;

		}

		bool isRightSubtreeGreater_HEAVY(BstNode *node, int value)
		{
			if (node == nullptr) return true;
			if (node->data > value
				&& isRightSubtreeGreater_HEAVY(node->left, value)
				&& isRightSubtreeGreater_HEAVY(node->right, value))
				return true;
			else return false;
		}

		bool isBinarySearchTree_HEAVY(BstNode *node)
		{
			//In binary search tree nodes on the left are equal or lower,
			//nodes on the right, are greater than actual node.
			if (node == nullptr) return true;
			if (isRightSubtreeGreater_HEAVY(node->right, node->data) 
				&& isLeftSubtreeLesserOrEqual_HEAVY(node->left, node->data)
				&& isBinarySearchTree_HEAVY(node->left)
				&& isBinarySearchTree_HEAVY(node->right))
				return true;
			else return false;
		}

		bool isBinarySearchTree(BstNode *node, int min = INT_MIN, int max = INT_MAX)
		{
			if (node == nullptr) return true;
			if (node->data > min
				&& node->data <= max
				&& isBinarySearchTree(node->left, min, node->data)
				&& isBinarySearchTree(node->right, node->data, max))
				return true;
			else return false;
		}

		bool isTreeFull(BstNode *node) {
			/*
				   x
				 /   \
				/     \
			   x       x
			  / \ 
			 x   x 
				/ \
				x x 
			Node must have either 0 or 2 children
			*/

			if (node->left == nullptr && node->right == nullptr)
				return true;

			else if (node->left != nullptr && node->right != nullptr)
			{
				if (isTreeFull(node->left) && isTreeFull(node->right))
					return true;
			}
			
			return false;
		}

		bool isTreeComplete(BstNode *node)
		{
			if (node == nullptr) return false;
			std::queue<BstNode*> q;
			q.push(node);

			while (!q.empty())
			{
				BstNode *current = q.front();
				q.pop();

				if (current == nullptr)
					break;

				q.push(current->left);
				q.push(current->right);
			}

			while (!q.empty())
			{
				if (q.front() != nullptr) return false;
				q.pop();
			}

			return true;
		}

		bool isTreeComplete_INDEX(BstNode *node) {
			//		  X
			//	     / \
			//		X	X
			//     / \   
			//    X   X
			// A complete binary tree is a binary tree in which every level, 
			//except possibly the last, is completely filled, and all nodes are as far left as possible.
			if (node == nullptr) return false;
			std::queue<BstNode*> q;
			std::queue<int> indexes;
			int index = 1;

			q.push(node);
			indexes.push(index);

			while (!q.empty())
			{
				BstNode *current = q.front();

				if (current->left != nullptr)
				{
					q.push(current->left);
					indexes.push(index * 2);
				}

				if (current->right != nullptr) 
				{
					q.push(current->right);
					indexes.push(index * 2 + 1);
				}

				index++;
				q.pop();
			}

			int f1 = indexes.front();
			indexes.pop();
			while (!indexes.empty())
			{
				int f2 = indexes.front();
				indexes.pop();

				if (f2 - f1 > 1) return false;

				f1 = f2;
			}
			return true;
		}

		bool isTreePerfect(BstNode *node)
		{
			/*
				   x
				 /   \
				/     \
			   x       x
			  / \     / \
			 x   x   x   x
			/ \ / \ / \ / \
			x x x x x x x x
			Must have exactly 2^n - 1 nodes. Also called Complete and full.
			*/

			if (node == nullptr) return false;
			std::queue<BstNode*> q;
			q.push(node);
			int size = 1;

			while (!q.empty())
			{
				BstNode *current = q.front();
				q.pop();

				if (current == nullptr)
					break;

				q.push(current->left);
				q.push(current->right);
				size += 2;
			}

			while (!q.empty())
			{
				if (q.front() != nullptr) return false;
				q.pop();
			}
			
			size++; // 2^n - 1 => 2^n
			return !(size & size - 1);

		}

		BstNode* deleteData(BstNode *node, int data)
		{
			if (node == nullptr) return node;
			else if (data < node->data) node->left = deleteData(node->left, data);
			else if (data > node->data) node->right = deleteData(node->right, data);
			else {
				//Case 1 - no child
				if (node->left == nullptr && node->right == nullptr)
				{
					delete node;
					node = nullptr;
				}
				//Case 2 - one child
				else if (node->left == nullptr)
				{
					BstNode *buf = node;
					node = node->left;
					delete buf;
				}

				else if (node->right == nullptr)
				{
					BstNode *buf = node;
					node = node->right;
					delete buf;
				}

				//Case 3 - two children
				else
				{
					BstNode *buf = getMinNode(node->right);
					node->data = buf->data;
					node->right = deleteData(node->right, buf->data);
				}
			}
			return node;
		}

		BstNode* createMinBst(int arr[], int start, int end)
		{
			if (end < start)
				return nullptr;

			int mid = (start + end) / 2;
			BstNode *n = new BstNode(arr[mid]);
			n->left = createMinBst(arr, start, mid - 1);
			n->right = createMinBst(arr, mid + 1, end);
			return n;
		}

		void createLevelLinkedList_preorder(BstNode *root, std::vector<LinkedLists<BstNode*>*> &lists, int level = 0)
		{
			if (root == nullptr) return;
			
			LinkedLists<BstNode*>* list = new LinkedLists<BstNode*>();
			if (lists.size() == level)
			{
				lists.push_back(list);
			}
			else
			{
				list = lists[level];
			}

			list->append(root);
			createLevelLinkedList_preorder(root->left, lists, level + 1);
			createLevelLinkedList_preorder(root->right, lists, level + 1);
		}

		std::vector<LinkedLists<BstNode*>*> createLevelLinkedList(BstNode* root)
		{
			std::vector<LinkedLists<BstNode*>*> result;
			LinkedLists<BstNode*> *current = new LinkedLists<BstNode*>();

			if (root != nullptr)
				current->append(root);

			while (current->size() > 0)
			{
				result.push_back(current);
				LinkedLists<BstNode*> *parents = current;
				current = new LinkedLists<BstNode*>();

				LinkedLists<BstNode*> *parent = parents;
				LinkedListNode<BstNode*> *runner = parent->root;
				
				while (runner != nullptr)
				{
					if (runner->data->left != nullptr)
						current->append(runner->data->left);
					if (parent->root->data->right != nullptr)
						current->append(runner->data->right);
					runner = runner->next;
				}
				/*for (auto parent : *parents){
					if (parent.left != nullptr)
						current->append(parent.left);
					if (parent.right != nullptr)
						current->append(parent.right);
				}*/
			}
			return result;
		}

		BstNode* leftMostChild(BstNode *root)
		{
			if (root == nullptr)
				return nullptr;

			BstNode *n = root;
			while (n->left != nullptr)
				n = n->left;

			return n;
		}

		BstNode* findNext(BstNode *root)
		{
			if (root == nullptr) return nullptr;

			if (root->right != nullptr) 
			{
				return leftMostChild(root->right);
			}

			else
			{
				BstNode *q = root;
				BstNode *x = q->parent;
				while (x != nullptr && x->left != q)
				{
					q = x;
					x = x->parent;
				}

				return x;
			}
		}



	};

	enum nodeState
	{
		visited = 0,
		visiting = 1,
		notVisited = 2
	};

	class Node
	{
	public:
		Node(int i)
		{
			this->val = i;
		}
		int val = 0;
		nodeState state = nodeState::notVisited;
	};

	class Edge
	{
	public:
		Edge(Node *v1, Node *v2)
		{
			start = v1;
			end = v2;
		}

		Node *start;
		Node *end;
	};

	class Graph
	{
	public:
		std::vector<Node*> vertexList;
		std::vector<Edge*> adjacentList;

		Node* addVertex(Graph g, int val)
		{
			vertexList.push_back(new Node(val));
			return vertexList.back();
		}

		std::vector<Node*> getAdjacent(Node *n)
		{
			std::vector<Node*> res;
			for (Edge *edge: adjacentList)
			{
				if (edge->start == n)
					res.push_back(edge->end);
			}
			return res;
		}

		void addEdge(Node *v1, Node *v2)
		{
			adjacentList.push_back(new Edge(v1, v2));
		}

		bool isRoute(Graph g, Node *start, Node *end)
		{
			std::queue<Node*> q;

			for (Node *u : g.vertexList)
			{
				u->state = nodeState::notVisited;
			}

			start->state = nodeState::visiting;
			q.push(start);

			Node *u = nullptr;
			while (!q.empty())
			{
				u = q.front();
				q.pop();
				if (u != nullptr)
				{
					for (Node *v : getAdjacent(u))
					{
						if (v->state == nodeState::notVisited)
						{
							if (v == end)
								return true;
							else {
								v->state = nodeState::visiting;
								q.push(v);
							}
						}
					}
					u->state = nodeState::visited;
				}
			}
			return false;
		}

		
	};

	//TODO tries
	//TODO heap
	//TODO red-black tries (balancing), O(operations) etc.

	template<typename X>
	void pr(X d, std::string label = "")
	{
		if (!label.empty())
			label = label + ": ";

		//if (d == nullptr)
		//{
		//	std::cout << label << "null" << std::endl;
		//	return;
		//}
			
		
		std::cout << label << d << std::endl;
	}

	template<typename X>
	void prPtr(X *d, std::string label = "")
	{
		if (!label.empty())
			label = label + ": ";

		if (d == nullptr)
		{
			std::cout << label << "null" << std::endl;
			return;
		}


		std::cout << label << *d << std::endl;
	}

	void test()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 14);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 16);
		bst.root = bst.insert(bst.root, 18);
		bst.root = bst.insert(bst.root, 0);
		bst.root = bst.insert(bst.root, 12);
		bst.root = bst.insert(bst.root, 4);
		bst.root = bst.insert(bst.root, 2);
		bst.root = bst.insert(bst.root, 8);
		bst.root = bst.insert(bst.root, 10);

		std::cout << bst.search(bst.root, 4) << std::endl;
		std::cout << bst.search(bst.root, 18) << std::endl;

		std::cout << "---" << std::endl;
		bst.print_preorder(bst.root);
		std::cout << "---" << std::endl;
		bst.print_inorder(bst.root);
		std::cout << "---" << std::endl;
		bst.print_postorder(bst.root);

		/*bst.root = bst.insert(bst.root, 2);
		bst.root = bst.insert(bst.root, 0);
		bst.root = bst.insert(bst.root, 1);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 5);
		bst.root = bst.insert(bst.root, 7);*/

		std::cout << "---" << std::endl;
		std::cout << bst.isTreeBalanced(bst.root) << std::endl;
		pr(bst.getMax(bst.root), "Max");
		pr(bst.getMin(bst.root), "Min");
		pr("-----");
		
		//bst.root->left->data = 123;
		pr(bst.isBinarySearchTree_HEAVY(bst.root), "isBSTheavy");
		pr(bst.isBinarySearchTree(bst.root), "isBST");

		Bst bst2;
		bst2.root = bst2.insert(bst2.root, 10);
		bst2.root = bst2.insert(bst2.root, 12);
		//bst2.root = bst2.insert(bst2.root, 11); without it, it is not complete
		//bst2.root = bst2.insert(bst2.root, 13);
		bst2.root = bst2.insert(bst2.root, 11);
		bst2.root = bst2.insert(bst2.root, 13);
		bst2.root = bst2.insert(bst2.root, 6);
		bst2.root = bst2.insert(bst2.root, 4);
		bst2.root = bst2.insert(bst2.root, 8);
		bst2.root = bst2.insert(bst2.root, 3);
		bst2.root = bst2.insert(bst2.root, 5);
		pr(bst.isTreeFull(bst.root), "Bst  isFull");
		pr(bst2.isTreeFull(bst2.root), "Bst2 isFull");

		bst.print_preorderToHeight(bst.root, 2);
		pr("---");
		bst.print_levelOrder(bst.root);

		pr(bst.isTreeComplete(bst.root), "Bst Complete");
		pr(bst2.isTreeComplete(bst2.root), "Bst2 Complete");

		pr("---");
		pr(bst.isTreePerfect(bst.root), "Bst Perfect");
		pr(bst2.isTreePerfect(bst2.root), "Bst2 Perfect");

		Bst bst3;
		bst3.root = bst3.insert(bst3.root, 10);
		bst3.root = bst3.insert(bst3.root, 15);
		bst3.root = bst3.insert(bst3.root, 6);

		bst3.root = bst3.insert(bst3.root, 12);
		bst3.root = bst3.insert(bst3.root, 17);
		bst3.root = bst3.insert(bst3.root, 4);
		bst3.root = bst3.insert(bst3.root, 8);

		bst3.root = bst3.insert(bst3.root, 3);
		//bst3.root = bst3.insert(bst3.root, 5);
		//bst3.root = bst3.insert(bst3.root, 7);
		//bst3.root = bst3.insert(bst3.root, 9);
		//bst3.root = bst3.insert(bst3.root, 16);
		//bst3.root = bst3.insert(bst3.root, 18);
		//bst3.root = bst3.insert(bst3.root, 11);
		//bst3.root = bst3.insert(bst3.root, 13);

		pr(bst3.isTreePerfect(bst3.root), "Bst3 Perfect");
		bst3.deleteData(bst3.root, 3);
		pr(bst3.isTreePerfect(bst3.root), "Bst3 Perfect");
		
		bst3.deleteData(bst3.root, 10);
		bst3.deleteData(bst3.root, 17);
		bst3.deleteData(bst3.root, 12);
		bst3.print_preorder(bst3.root);
	}

	void taskOne()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 14);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 16);

		std::cout << bst.isTreeBalanced(bst.root) << std::endl;
	}

	void taskTwo()
	{
		Graph g;
		auto v1 = g.addVertex(g, 1);
		auto v2 = g.addVertex(g, 2);
		auto v3 = g.addVertex(g, 3);
		auto v4 = g.addVertex(g, 4);
		auto v5 = g.addVertex(g, 5);

		g.addEdge(v1, v2);
		g.addEdge(v2, v4);
		g.addEdge(v4, v3);
		g.addEdge(v3, v1);
		g.addEdge(v3, v4);
		g.addEdge(v3, v5);

		pr(g.isRoute(g, v1, v5), "isRoute");

	}

	void taskThree()
	{
		Bst bst;
		int array[9] =
		{   1,  4,  7,
			10, 13, 16,
			19, 22, 25 };
		bst.root = bst.createMinBst(array, 0, 8);
		bst.print_preorder(bst.root);
	}

	void taskFour()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 14);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 4);
		bst.root = bst.insert(bst.root, 8);
		bst.root = bst.insert(bst.root, 12);
		bst.root = bst.insert(bst.root, 16);
		bst.root = bst.insert(bst.root, 15);
		bst.root = bst.insert(bst.root, 18);

		std::vector<LinkedLists<BstNode*>*> ll_vec;
		bst.createLevelLinkedList_preorder(bst.root, ll_vec);
		std::vector<LinkedLists<BstNode*>*> ll_vec2 = bst.createLevelLinkedList(bst.root);
	}

	void taskFive()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 14);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 16);
		//bst.root->left->data = 13123132;
		pr(bst.isBinarySearchTree(bst.root), "isBST");
	}

	void taskSix()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 3);
		bst.root = bst.insert(bst.root, 8);
		bst.root = bst.insert(bst.root, 13);
		bst.root = bst.insert(bst.root, 12);
		bst.root = bst.insert(bst.root, 14);
		
		prPtr(&bst.findNext(bst.root)->data);

		BstNode *bst14 = bst.root->right->right;
		prPtr(&bst.findNext(bst14)->data);

		BstNode *bst13 = bst.root->right->left;
		prPtr(&bst.findNext(bst13)->data);

		BstNode *bst6 = bst.root->left;
		prPtr(&bst.findNext(bst6)->data);

		BstNode *bst8 = bst.root->left->right;
		prPtr(&bst.findNext(bst8)->data);
	}

	void taskSeven()
	{
		Bst bst;
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 3);
		bst.root = bst.insert(bst.root, 8);
		bst.root = bst.insert(bst.root, 9);
		bst.root = bst.insert(bst.root, 13);
		bst.root = bst.insert(bst.root, 12);
		bst.root = bst.insert(bst.root, 14);
		BstNode *r = nullptr;
		BstNode *bst14 = bst.root->right->right;
		BstNode *bst13 = bst.root->right->left;
		BstNode *bst6 = bst.root->left;
		BstNode *bst8 = bst.root->left->right;
		BstNode *bst9 = bst.root->left->right->right;
		BstNode *bst3 = bst.root->left->left;
		r = bst.commonAncestor(bst.root, bst8, bst6);
		pr(r->data);

		/*r = bst.commonAncestor(bst.root, bst8, bst9);
		pr(r->data);

		r = bst.commonAncestor(bst.root, bst8, bst3);
		pr(r->data);

		r = bst.commonAncestor(bst.root, bst9, bst3);
		pr(r->data);

		r = bst.commonAncestor(bst.root, bst13, bst14);
		pr(r->data);

		r = bst.commonAncestor(bst.root, bst3, bst14);
		pr(r->data);*/
	}

	void taskEight()
	{
		Bst bst1;
		bst1.root = bst1.insert(bst1.root, 10);
		bst1.root = bst1.insert(bst1.root, 6);
		bst1.root = bst1.insert(bst1.root, 4);
		bst1.root = bst1.insert(bst1.root, 8);
		bst1.root = bst1.insert(bst1.root, 7);
		bst1.root = bst1.insert(bst1.root, 9);

		Bst bst2;
		bst2.root = bst2.insert(bst2.root, 8);
		bst2.root = bst2.insert(bst2.root, 7);
		bst2.root = bst2.insert(bst2.root, 9);
		//bst2.root = bst2.insert(bst2.root, 4);
		//bst2.root = bst2.insert(bst2.root, 7);
		//bst2.root = bst2.insert(bst2.root, 8);
		
		pr(bst2.containsTree(bst1.root, bst2.root), "does t1, contain t2");
	}

	void taskNine()
	{
	}

}