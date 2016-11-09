#include "stdafx.h"
#include "Others1.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <array>
#include <time.h>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <mutex>
#include <thread>

class TreeNode
{
public:
	int value;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val)
	{
		this->value = val;
	}
};

class Node
{
public:
	int value;
	Node *next = nullptr;

	Node(int value)
	{
		this->value = value;
	}
};

class LinkedList
{
public:
	Node *root = nullptr;
	Node *last = nullptr;

	void add(int i)
	{
		if (root == nullptr)
		{
			root = new Node(i);
			last = root;
		}
		else {
			Node *node = root;
			while (node->next != nullptr)
				node = node->next;
			node->next = new Node(i);
			last = node->next;
		}
	}

	void reverse()
	{
		//1 look for last
		std::stack<Node*> stack;
		Node *node = root;
		while (node != nullptr)
		{
			stack.push(node);
			node = node->next;
		}
		root->next = nullptr;

		if (stack.size() != 0) 
		{
			root = stack.top();
			stack.pop();
		}

		node = root;
		while (stack.size() != 0)
		{
			node->next = stack.top(); 
			stack.pop();
			node = node->next;
		}

		
		
		//2
	}

	void print()
	{
		Node *node = root;
		while (node != nullptr)
		{
			std::cout << node->value << " ";
			node = node->next;
		} std::cout << std::endl;
	}
};

enum traversalOrder {
	preorder = 1,
	inorded = 2,
	postorder = 3
};

class Tree
{
	TreeNode *root = nullptr;
	void printPreOrder(TreeNode *node, traversalOrder order)
	{
		if (node == nullptr) return;
		if (order == traversalOrder::preorder) 
			std::cout << node->value << std::endl;
		printPreOrder(node->left, order);
		if (order == traversalOrder::inorded)
			std::cout << node->value << std::endl;
		printPreOrder(node->right, order);
		if (order == traversalOrder::postorder)
			std::cout << node->value << std::endl;
	}

	int getHeight(TreeNode* node)
	{
		if (node == nullptr)
			return 0;

		int hleft = getHeight(node->left);
		int hright = getHeight(node->right);

		return std::max(hleft, hright) + 1;
		
	}

public:
	void add(int val, TreeNode* node)
	{
		if (val < node->value)
		{
			if (node->left != nullptr)
				add(val, node->left);
			else node->left = new TreeNode(val);
		}
		else
		{
			if (node->right != nullptr)
				add(val, node->right);
			else node->right = new TreeNode(val);
		}
	}

	void add(int val)
	{
		if (root == nullptr)
			root = new TreeNode(val);
		else add(val, root);
	}

	int height()
	{
		return getHeight(root);
	}

	void print(traversalOrder order = traversalOrder::inorded)
	{
		if (order == traversalOrder::inorded) std::cout << "Inorderd:\n";
		else if (order == traversalOrder::postorder) std::cout << "Postorder:\n";
		else if (order == traversalOrder::preorder) std::cout << "Preorder:\n";
		printPreOrder(root, order);
		std::cout << std::endl;
	}

	int sumAtDeepest()
	{
		if (root == nullptr) return -1;
		int height = getHeight(root) - 1;
		TreeNode *node = root;
		
		std::queue<TreeNode*> queue;
		std::queue<int> queHight;

		queue.push(node);
		queHight.push(0);
		int sum = 0;
		while (!queue.empty())
		{
			TreeNode *current = queue.front();
			int currHeight = queHight.front();

			if (currHeight == height) sum += current->value;
			if (current->left != nullptr)
			{
				queHight.push(currHeight + 1);
				queue.push(current->left);
			}

			if (current->right != nullptr)
			{
				queHight.push(currHeight + 1);
				queue.push(current->right);
			}

			queue.pop();
			queHight.pop();
		}
		return sum;
	}
};

void Others1::task1()
{
	//reverse linkedlst
	std::list<int> lst = { 3, 1, 2, 5, 6, 8, 10, 12 };
	lst.reverse();
	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	} std::cout << std::endl;
}

void Others1::task1a()
{
	//reverse linkedlst
	LinkedList lst;
	lst.add(3); lst.add(1); lst.add(2); lst.add(5); lst.add(6); lst.add(8); lst.add(10); lst.add(12);
	lst.print();
	lst.reverse();
	lst.print();
}

void Others1::task2()
{
	//sum at deepest (leafs)
	Tree tree;
	tree.add(5); tree.add(3); tree.add(9); tree.add(8); tree.add(1); tree.add(4); tree.add(11); tree.add(12);
	tree.print();
	tree.print(traversalOrder::postorder);
	tree.print(traversalOrder::preorder);
	std::cout << tree.height() << std::endl;
	std::cout << std::endl; 
	std::cout << tree.sumAtDeepest();
}

void Others1::task3()
{
	//leetcode 2 sum (two arr[indices] summing up to specific value)
	int target = 9;
	int arr[6] = { 15, 7, 11, 2, 9, 5 };
	std::map<int, int> map;

	for (int i = 0; i < 6; ++i)
	{
		int complement = target - arr[i];
		auto key = map.find(complement);
		if (key != map.end())
		{
			std::cout << "K:V:1 - " << key->first << " " << key->second << "\tK:V:2 - " << arr[i] << " " << i;
			break;
		}
		
		map.insert(std::make_pair(arr[i], i));
	}
}

void Others1::task4()
{
	//Given two sorted lists, write a function that merges them and then sorts them.
	std::vector<int> l1 = { 1, 3, 5 , 7, 9, 11 };
	std::vector<int> l2 = { 2, 4, 6, 8, 10, 12, 20 };
	std::vector<int> res(l1.size() + l2.size());
	int i = 0; int j = 0; int k = 0;
	while (i < l1.size() && j < l2.size())
	{
		if (l1[i] < l2[j])
		{
			res[k] = l1[i];
			++i;
		}
		else
		{
			res[k] = l2[j];
			++j;
		}
		++k;
	}
	
	while (i < l1.size())
	{
		res[k] = l1[i];
		++i;
		++k;
	}

	while (j < l2.size())
	{
		res[k] = l2[j];
		++j;
		++k;
	}

	for (int i = 0; i < res.size(); ++i)
		std::cout << res[i] << " ";
	std::cout << std::endl;


}

bool checkParenthesisStack(std::string str)
{
	std::stack<int> stack;
	char openBracket = '(';
	char closingBracket = ')';
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == openBracket)
			stack.push(openBracket);
		else if (str[i] == closingBracket)
		{
			if (stack.size() != 0)
				stack.pop();
			else
				return false;
		}
	}
	if (stack.size() != 0) return false;
	return true;
}

bool checkParenthesisCount(std::string str)
{
	int counter = 0;
	char openBracket = '(';
	char closingBracket = ')';
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == openBracket)
			++counter;
		else if (str[i] == closingBracket)
		{
			--counter;
			if (counter < 0)
				return false;
		}
	}
	if (counter > 0) return false;
	return true;
}

bool checkParenthesisRecursion(std::string str)
{

	return true;
}

void Others1::task5()
{
	//Paranthesiss unbalance
	//stack method // universal - covers all types of brackets
	//count method // one type of brackets
	//recursion method? - not worth?
	std::string str = "S(ome(string)with((open)andClsoing)Brack(e)t((((s)))s)()(()))"; //valid
	//std::string str = "S(ome(string)with((open)andClsoing)Brack(e)t((((s)))s)()(())))"; //unvalid
	//std::string str = "S)(ome(string)with((open)andClsoing)Brack(e)t((((s)))s)()(()))"; //unvalid
	//std::string str = "(S(ome(string)with((open)andClsoing)Brack(e)t((((s)))s)()(()))"; //unvalid
	//std::string str = "S(ome(string)with((open)andClsoing)Brack(e)t((((s)))s)()(()))("; //unvalid
	if (checkParenthesisStack(str) && checkParenthesisCount(str) && checkParenthesisRecursion(str))
		std::cout << "String parenthesis are valid\n";
	else std::cout << "String parenthesis are invalid\n";
}




std::mutex mtx;
void next(const std::set<char> &letters, std::string &actual)
{
	
	int i = actual.length() - 1;
	char letter = actual[i];
	while (letter == 'z' && i > 0)
	{
		--i;
		letter = actual[i];
	}

	if (i == 0 && (letter == 'z'))
	{
		for (int x = 0; x < actual.length(); ++x)
			actual[x] = '0';
		actual = actual + "0";
	}
	else
	{
		auto it = std::find(letters.begin(), letters.end(), actual[i]);
		actual[i] = *(++it);

		for (i = i + 1; i < actual.size(); ++i)
			actual[i] = '0';
		
	}
}

//62 in total
std::set<char> letters = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', //10
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'I', 'J', 'H', 'L', 'K', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', //26
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i', 'j', 'h', 'l', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //26
std::string actual = "0";

void doTest()
{
	for (int i = 0; i < 1; ++i)
	{
		mtx.lock();
		next(letters, actual);
		mtx.unlock();
	}
	std::cout << actual << std::endl;
}

void Others1::task6()
{
	//shortening url
	std::thread threads[8];
	// spawn 10 threads:
	for (int i = 0; i< 8; ++i)
		threads[i] = std::thread(doTest);

	for (auto& th : threads) th.join();
}

int maxSubarray1(std::vector<int> arr)
{
	int max_end = 0;
	int max_current = 0;
	
	for (int i = 0; i < arr.size(); ++i)
	{
		max_end = std::max(0, max_end + arr[i]);
		max_current = std::max(max_current, max_end);
	}
	return max_current;
}

int maxSubarray2(std::vector<int> arr)
{
	int max_end = arr[0];
	int max_current = arr[0];

	for (int i = 1; i < arr.size(); ++i)
	{
		max_end = std::max(arr[i], max_end + arr[i]);
		max_current = std::max(max_current, max_end);
	}
	return max_current;
}

void Others1::task7()
{
	std::vector<int> arr = { -3, 100, -4, -2, 9, -63, -200, 55 };
	std::cout << maxSubarray1(arr) << std::endl;
	std::cout << maxSubarray2(arr) << std::endl;
}