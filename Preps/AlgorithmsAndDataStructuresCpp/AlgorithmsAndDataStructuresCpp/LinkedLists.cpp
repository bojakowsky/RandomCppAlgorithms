#include "stdafx.h"
#include <iostream>
#include "LinkedLists.h"
#include <sstream>
#include <algorithm>

namespace linkedLists
{
	template<class T> class Node
	{
	public:
		Node(T d)
		{
			this->data = d;
		}

		~Node() { }

		Node *next = nullptr;
		T data;

		void appendToTail(T d)
		{
			Node *n = this;
			while (n->next != nullptr)
				n = n->next;

			n->next = new Node(d);
		}

		Node* deleteNode(Node *head, T d)
		{
			Node *n = head;
			if (n->data == d)
			{
				n = n->next;
				return n;
			}

			while (n->next != nullptr)
			{
				if (n->next->data == d)
				{
					Node *nn = n->next->next;
					n->next = nn;
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
			std::cout << "NULL";
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
	}

	void taskOne()
	{

	}

	void taskTwo()
	{

	}

	void taskThree()
	{

	}

	void taskFour()
	{

	}

	void taskFive()
	{

	}

	void taskSix()
	{

	}

	void taskSeven()
	{

	}
}