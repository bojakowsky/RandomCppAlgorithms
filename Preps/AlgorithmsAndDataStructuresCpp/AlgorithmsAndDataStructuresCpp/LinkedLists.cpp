#include "stdafx.h"
#include <iostream>
#include "LinkedLists.h"
#include <sstream>
#include <algorithm>
#include <memory>
#include <unordered_set>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <list>
namespace linkedLists
{
	template<class T> class smartNode
	{
	public:
		smartNode(T d)
		{
			this->data = d;
		}

		std::shared_ptr<smartNode> next = nullptr;
		T data;
	};

	template<class T> class LinkedList
	{
	public:
		//std::move allows to move unique pointers;
		LinkedList(T d)
		{
			this->root = std::make_shared<smartNode<T>>(d);
		}

		void appendToTail(T d)
		{
			smartNode<T>* n = this->root.get();
			while (n->next != nullptr)
				n = n->next.get();
			n->next = std::make_shared<smartNode<T>>(d);
		}

		void printAllNodes()
		{
			smartNode<T>* n = this->root.get();
			std::cout << n->data << " -> ";
			while (n->next != nullptr)
			{
				n = n->next.get();
				std::cout << n->data << " -> ";
			}
			std::cout << "NULL\n";
		}
	private:
		std::shared_ptr<smartNode<T>> root;
	};

	template<class T> class Node
	{
	public:
		Node() {

		}

		Node(T d)
		{
			this->data = d;
		}

		~Node() { }

		Node *next = nullptr;
		//Added for task 2.6
		Node *prev = nullptr;
		T data;

		void appendToTail(T d)
		{
			Node *n = this;
			while (n->next != nullptr)
				n = n->next;

			n->next = new Node<T>(d);
		}

		Node* deleteNode(Node *head, T d)
		{
			Node *n = head;
			if (n->data == d)
			{
				n = n->next;
				delete head;
				return n;
			}

			while (n->next != nullptr)
			{
				if (n->next->data == d)
				{
					Node *tmp = n->next->next;
					delete n->next;
					n->next = tmp;

					return head;
				}
				n = n->next;
			}
			return head;
		}

		void printAllNodes()
		{
			Node *n = this;
			std::cout << this->data << " -> ";
			while (n->next != nullptr) 
			{
				n = n->next;
				std::cout << n->data << " -> ";
				
			}
			std::cout << "NULL\n";
		}

		void printAllNodesWithBreak(int breakVal = 10)
		{

			Node *n = this;
			std::cout << this->data << " -> ";
			while (n->next != nullptr)
			{
				n = n->next;
				std::cout << n->data << " -> ";
				if (!breakVal)
					break;
				--breakVal;
			}
			std::cout << "NULL\n";
		}
	};

	template <class T> class dNode
	{
		dNode *next = nullptr;
		dNode *prev = nullptr;
		T d;
	};

	void test1()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list = list->deleteNode(list, 1);
		list = list->deleteNode(list, 3);
		list->printAllNodes();
		delete list;

		std::cout << std::endl;

		std::unique_ptr<LinkedList<int>> smartList(new LinkedList<int>(1));
		smartList->appendToTail(2);
		smartList->appendToTail(3);
		smartList->appendToTail(4);
		smartList->printAllNodes();
	}

	void removeDuplicates_way1(Node<int> *root)
	{
		std::unordered_set<int> buf;
		Node<int> *n = root;
		Node<int> *prev = nullptr;
		while (n != nullptr)
		{
			std::unordered_set<int>::iterator it = buf.find(n->data);
			if (it != buf.end())
			{
				prev->next = n->next;
				delete n;
				n = prev;
			}
			else
			{
				buf.insert(n->data);
				prev = n;	
			}
			n = n->next;
		}

	}

	void removeDuplicates_way2(Node<int> *root)
	{
		Node<int> *current = root;
		while (current != nullptr)
		{
			Node<int> *runner = current;
			while (runner->next != nullptr)
			{
				if (runner->next->data == current->data)
				{
					Node<int> *buf = runner->next->next;
					delete runner->next;
					runner->next = buf;
				}
				else
					runner = runner->next;
			}
			current = current->next;
		}
	}

	void taskOne()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(5);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list->appendToTail(3);
		list->appendToTail(2);
		list->appendToTail(2);
		list->appendToTail(2);
		list->appendToTail(1);
		list->appendToTail(4);
		removeDuplicates_way2(list);
		list->printAllNodes();

	}

	Node<int> *getKtxElement(Node<int> *root, int k)
	{
		if (k < 0) return nullptr;
		if (root == nullptr) return nullptr;
		Node<int> *p1 = root;
		Node<int> *p2 = root;
		while (p2->next != nullptr && k > 0)
		{
			p2 = p2->next;
			--k;
		}
		if (k > 0) return nullptr;
		while (p2->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}

	Node<int> *getKthElementRecursive(Node<int> *node, int k, int &i)
	{
		if (node == nullptr) return nullptr;
		if (k <= 0) return nullptr;

		Node<int> *n = getKthElementRecursive(node->next, k, i);
		++i;
		if (k == i)
			return node;
		return n;
	}
	
	void printKtxElement2(Node<int> *node, int k) {
		int i = 0;
		Node <int> *kth = getKthElementRecursive(node, k, i);
		if (kth != nullptr)
			std::cout << std::endl << k << ": " << kth->data;
		else std::cout << std::endl << k << ": " << "nullptr";
	}

	void printKtxElement(Node<int> *node, int k) {
		Node <int> *kth = getKtxElement(node, k);
		if (kth != nullptr)
			std::cout << std::endl << k << ": " << kth->data;
		else std::cout << std::endl << k << ": " << "nullptr";
	}
	void taskTwo()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list->appendToTail(5);
		list->printAllNodes();
		
		for (int i = 0; i < 7; ++i)
			printKtxElement(list, i);
	}

	void taskTwoRecursive()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list->appendToTail(5);
		list->printAllNodes();

		for (int i = 0; i < 7; ++i)
			printKtxElement2(list, i);
	}

	bool deleteNodeInTheMiddle(Node<int> *node)
	{
		if (node == nullptr || node->next == nullptr) return false;
		Node<int> *buf = node->next;
		node->next = buf->next;
		node->data = buf->data;
		delete buf;
		return true;
	}

	void taskThree()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list->appendToTail(5);
		list->printAllNodes();

		Node<int> *end = list;
		end = end->next; // 2
		end = end->next; // 3
		Node<int> *mid = end;
		end = end->next; // 4
		end = end->next; // 5

		if (deleteNodeInTheMiddle(mid)) std::cout << "One node has been deleted" << std::endl;
		else std::cout << "One node has NOT been deleted" << std::endl;
		if (deleteNodeInTheMiddle(end)) std::cout << "Second node has been deleted" << std::endl;
		else std::cout << "Second node has NOT been deleted" << std::endl;
		list->printAllNodes();

	}

	Node<int> *partition2(Node<int> *node, int x)
	{
		Node<int> *s = nullptr;
		Node<int> *ge = nullptr;
		while (node != nullptr)
		{
			Node<int> *n = node->next;
			if (node->data < x)
			{
				node->next = s;
				s = node;
			}
			else
			{
				node->next = ge;
				ge = node;
			}
			node = n;
		}

		Node <int> *n = s;
		while (n->next != nullptr)
			n = n->next;
		n->next = ge;

		s->printAllNodes();
		return s;
	}

	Node<int> *partition1(Node<int> *node, int x)
	{
		Node<int> *smaller = nullptr;
		Node<int> *smallerRoot = nullptr;

		Node<int> *greater = nullptr;
		Node<int> *greaterRoot = nullptr;

		while (node != nullptr)
		{
			Node <int> *runner = node->next;
			node->next = nullptr;
			if (node->data < x)
			{
				if (smaller != nullptr)
				{
					smaller->next = node;
					smaller = smaller->next; // or smaller->next is now node so also smaller = node; is appropriate
				}
				else
				{
					smaller = node;
					smallerRoot = node;
				}
			}
			else
			{
				if (greater != nullptr)
				{
					greater->next = node;
					greater = greater->next; // same here;
				}
				else
				{
					greater = node;
					greaterRoot = node;
				}
			}
			node = runner;
		}

		smaller->next = greaterRoot;
		smallerRoot->printAllNodes();
		return smallerRoot;
	}
	void taskFour()
	{
		Node<int> *list = new Node<int>(1);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(4);
		list->appendToTail(5);
		list->appendToTail(2);
		list->appendToTail(3);
		list->appendToTail(9);
		list->appendToTail(10);
		list->appendToTail(1);
		list->appendToTail(15);
		list->appendToTail(6);
		list->appendToTail(7);
		partition2(list, 4);
		//partition1(list, 3);
	}
	Node<int>* addListsRec(Node<int> *n1, Node<int> *n2, int carry = 0)
	{
		if (n1 == nullptr && n2 == nullptr && carry == 0)
			return nullptr;

		Node<int> *res = new Node<int>(0);
		int sum = carry;
		if (n1 != nullptr)
			sum += n1->data;
		if (n2 != nullptr)
			sum += n2->data;
		res->data = sum % 10;

		if (n1 != nullptr || n2 != nullptr)
		{
			Node<int>* more = addListsRec(
				n1 == nullptr ? nullptr : n1->next,
				n2 == nullptr ? nullptr : n2->next,
				sum >= 10 ? 1 : 0);
			res->next = more;
		}
		return res;

	}

	Node<int>* addLists(Node<int> *n1, Node<int> *n2)
	{
		if (n1 == nullptr && n2 == nullptr) return nullptr;
		else if (n1 == nullptr) return n2;
		else if (n2 == nullptr) return n1;

		// 3 5 1
		// 9 4 2 +
		// ---------
		// 1 2 9 3 
		Node<int> *res = new Node<int>(-1);
		Node<int> *root = res;
		Node<int> *r1 = n1;
		Node<int> *r2 = n2;
		int carry = 0;
		bool run = true;
		while (run)
		{
			int sum = carry;
			if (r1 != nullptr) 
			{
				sum += r1->data;
				r1 = r1->next;
			}
			if (r2 != nullptr)
			{
				sum += r2->data;
				r2 = r2->next;
			}
			
			res->data = sum % 10;
			carry = sum >= 10 ? 1 : 0;
			//carry = sum / 10;

			if (r1 != nullptr || r2 != nullptr || carry != 0)
			{
				res->next = new Node<int>();
				res = res->next;
			}
			else run = false;
		}
		return root;
	}

	int getLength(Node<int> *n)
	{
		if (n == nullptr) return 0;
		Node<int> *r = n;

		int i = 1;
		while (r->next != nullptr)
		{
			r = r->next;
			++i;
		}
		return i;
	}

	Node<int>* padList(Node<int>* list, int padding)
	{
		Node<int>* head = list;
		for (int i = 0; i < padding; ++i)
		{
			Node<int>* n = new Node<int>(0);
			//head->prev = n;
			n->next = head;
			head = n; // we can't return n, so we assign it to head
		}
		return head;
	}

	class PartialSum
	{
	public:
		Node<int>* sum = nullptr;
		int carry = 0;
	};

	Node<int>* insertBefore(Node<int>* list, int data)
	{
		Node<int>* node = new Node<int>(data);
		if (list != nullptr)
		{
			//list->prev = node;
			node->next = list;
		}
		return node;
	}

	PartialSum* addListsHelper(Node<int>* list1, Node<int>* list2)
	{
		if (list1 == nullptr && list2 == nullptr)
			return new PartialSum();

		PartialSum *sum = addListsHelper(list1->next, list2->next);
		int val = list1->data + list2->data + sum->carry;

		Node<int>* result = insertBefore(sum->sum, val % 10);
		sum->sum = result;
		sum->carry = val / 10;
		return sum;
	}

	Node<int>* addLists2(Node<int>* list1, Node<int>* list2)
	{
		int len1 = getLength(list1);
		int len2 = getLength(list2);

		if (len1 < len2)
		{
			list1 = padList(list1, len2 - len1);
		}
		else
		{
			list2 = padList(list2, len1 - len2);
		}
		
		PartialSum *sum = addListsHelper(list1, list2);
		if (sum->carry == 0)
			return sum->sum;
		else {
			Node<int>* result = insertBefore(sum->sum, sum->carry);
			return result;
		}
	}

	void taskFive()
	{
		/*
		Node<int> *list1 = new Node<int>(7);
		list1->appendToTail(1);
		list1->appendToTail(6);
		Node<int> *list2 = new Node<int>(5);
		list2->appendToTail(9);
		list2->appendToTail(2);

		//addLists(list1, list2)->printAllNodes();
		auto l = addListsRec(list1, list2); 
		l->printAllNodes();
		std::cout << getLength(l);
		*/
		//FOLLOW UP
		Node<int> *list1 = new Node<int>(1);
		list1->appendToTail(2);
		list1->appendToTail(3);
		list1->appendToTail(4);
		Node<int> *list2 = new Node<int>(5);
		list2->appendToTail(6);
		list2->appendToTail(7);

		list1->printAllNodes();
		list2->printAllNodes();
		addLists2(list1, list2)->printAllNodes();
		
	}



	Node<int>* findBeginning(Node<int>* head)
	{
		Node<int>* n = head;
		Node<int>* n2 = head;
		while (n2 != nullptr && n2->next != nullptr)
		{
			n = n->next;
			n2 = n2->next->next;
			if (n == n2) break;
		}
		
		if (n2 == nullptr || n2->next == nullptr)
			return nullptr;

		n = head;
		while (n != n2)
		{
			n = n->next;
			n2 = n2->next;
		}

		return n;
	}

	void taskSix()
	{
		Node<int> *list1 = new Node<int>(1);
		list1->appendToTail(2);
		list1->appendToTail(3);
		list1->appendToTail(4);
		list1->appendToTail(5);
		Node<int> *second = list1;
		second = second->next;
		Node<int> *end = list1;
		while (end->next != nullptr)
			end = end->next;
		end->next = second;
		//1 -> 2 -> 3 -> 4 -> 5 -> // 2 -> 3.. loop
		findBeginning(list1)->printAllNodesWithBreak();
	}

	bool isPalindrome(Node<int>* list)
	{
		Node<int>* n = list;
		Node<int>* n2 = list;
		std::stack<int> stack;
		while (n2 != nullptr && n2->next != nullptr)
		{
			stack.push(n->data);
			n = n->next;
			n2 = n2->next->next;
		}

		if (n2 != nullptr)
			n = n->next;

		while (n != nullptr)
		{
			int val = stack.top();
			stack.pop();

			if (val != n->data)
				return false;
			n = n->next;
		}
		return true;
	}

	class Result
	{
	public:
		Result() {}
		Result(Node<int>* node, bool isPali)
		{
			this->res = node;
			this->isPalindrome = isPali;
		}

		Node<int>* res = nullptr;
		bool isPalindrome = false;
	};

	Result* isPalindromeRec(Node<int>* list, int length)
	{
		if (length == 0) {
			return new Result(list, true);
		}
		else if (length == 1)
		{
			return new Result(list->next, true);
		}

		Result* res = isPalindromeRec(list->next, length - 2);
		if (res->res->data != list->data && res->isPalindrome)
			res->isPalindrome = false;
		res->res = res->res->next;
		return res;
		//length: 5 -> 3 -> 1 // data: 1 -> 2 -> 3
		
		//1(2(3)2)1
	}

	bool isPalRec(Node<int>* list, int length)
	{
		Result *res = isPalindromeRec(list, length);
		bool result = res->isPalindrome;
		delete res;

		return result;
	}

	void taskSeven()
	{
		/*Node<int> *list1 = new Node<int>(1);
		list1->appendToTail(2);
		list1->appendToTail(3);
		list1->appendToTail(2);
		list1->appendToTail(1);*/
		Node<int> *list1 = new Node<int>(1);
		list1->appendToTail(2);
		list1->appendToTail(6);
		list1->appendToTail(3);
		list1->appendToTail(7);
		list1->appendToTail(3);
		list1->appendToTail(6);
		list1->appendToTail(2);
		list1->appendToTail(1);
		std::cout << isPalindrome(list1) << std::endl;
		std::cout << isPalRec(list1, getLength(list1)) << std::endl;
	}

	void simpleListTest()
	{
		std::list<int> lst = { 2, 1 };
		if (1)
			lst.begin();
		if (2)
			lst.end();

	}
}