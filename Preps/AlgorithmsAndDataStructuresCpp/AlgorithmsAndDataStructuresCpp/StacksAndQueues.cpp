#include "stdafx.h"
#include "StackAndQueues.h"
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <forward_list>
#include <typeinfo>
#include <string>


///////
template<class T> class NNode
{
public:
	NNode() {

	}

	NNode(T d)
	{
		this->data = d;
	}

	~NNode() { }
	NNode *next = nullptr;
	//Added for task 2.6
	NNode *prev = nullptr;
	T data;

	void appendToTail(T d)
	{
		if (this->data == nullptr)
			this->data = d;
		else {
			NNode *n = this;
			while (n->next != nullptr)
				n = n->next;

			n->next = new NNode<T>(d);
		}
	}

	NNode* deleteNode(NNode *head, T d)
	{
		NNode *n = head;
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
				NNode *tmp = n->next->next;
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
		NNode *n = this;
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

		NNode *n = this;
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
//////


//Task 2
class Min
{
public:
	Min()
	{

	}

	void addMin(int val)
	{
		if (val <= getMin())
		{
			history->push(val);
		}
	}

	void popMin(int val)
	{
		if (getMin() == val)
			history->pop();
	}

	int getMin() {
		if (history->size() == 0) return INT_MAX;
		return history->top();
	}

private:
	//myStack *history = new myStack();
	std::stack<int> *history = new std::stack<int>();

	//int min = INT_MAX;
};

class Node {
public:
	Node(){}
	Node(int data)
	{
		this->data = data;
	}

	Node(Node* n, int data)
	{
		this->next = n;
		this->data = data;
	}

	Node* next = nullptr;
	int data;
};

class myStack {
private:
	Node* _top = nullptr;
public:
	~myStack()
	{

	}

	void push(int data)
	{
		Node* t = new Node(data);
		t->next = _top;
		_top = t;
	}

	void pop()
	{
		if (_top != nullptr)
		{
			Node *newTop = _top->next;
			delete _top;
			_top = newTop;
		}
	}

	int top()
	{
		return _top->data;
	}

	void pushWithMin(int data)
	{
		Node* t = new Node(data);
		t->next = _top;
		_top = t;
		min.addMin(data);
	}

	void popWithMin()
	{
		if (_top != nullptr)
		{
			min.popMin(_top->data);
			Node *newTop = _top->next;
			delete _top;
			_top = newTop;
		}
	}

	Min min;
};

class myQueue {
private:
	Node* _back = nullptr;
	Node* _front = nullptr;
public:
	void pop() 
	{
		if (_front != nullptr)
		{
			Node *front = _front->next;
			delete _front;
			_front = front;
		}
		//return nullptr;
	}

	void push(int data)
	{
		//we add the data to the end of the queue 
		//to the back, to be more precise
		if (_front == nullptr)
		{
			Node *node = new Node(data);
			_front = node;
			_back = node;
			//1 front
			//1 back
		}
		else {
			Node *node = new Node(data);
			_back->next = node; 
			_back = node;		
		}
	}

	int front()
	{
		return _front->data;
	}

	int back()
	{
		return _back->data;
	}



};

void stackAndQueues::test()
{
	myStack *stack = new myStack();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	std::cout << stack->top() << std::endl;
	stack->pop();
	std::cout << stack->top() << std::endl;
	stack->pop();
	std::cout << stack->top() << std::endl;
	stack->pop();
	std::cout << stack->top() << std::endl;
	stack->pop();
	//std::cout << stack->top() << std::endl;

	delete stack;

	//std::stack<int> st;
	/*st.empty();
	st.pop();
	st.push(1);
	st.top();*/

	/*std::queue<int> que;
	que.push(1);
	std::cout << que.back() << std::endl; 
	std::cout << que.front() << std::endl;
	que.pop();*/
	//std::cout << que.back() << std::endl; // Error!
	//std::cout << que.front() << std::endl; // Error!

	myQueue que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	std::cout << que.front() << " " << que.back() << std::endl;
	que.pop();
	std::cout << que.front() << " " << que.back() << std::endl;
	que.pop();
	std::cout << que.front() << " " << que.back() << std::endl;
	que.pop();
	std::cout << que.front() << " " << que.back() << std::endl;
	que.pop();
	//std::cout << que.front() << " " << que.back() << std::endl;
	//que.pop();
	
	
	
	
}

class ArrayFixedSizeThreeStack {
private:
	int size = 0;
	int *arr = nullptr;
	int *pointer[3];
	int intPointer[3] = { -1, -1, -1 };
public:
	ArrayFixedSizeThreeStack(int stackSize)
	{
		size = stackSize;
		arr = new int[size * 3]();
		//throw new std::exception("blablalbla");
		pointer[0] = &arr[0];
		std::cout << *pointer[0] << std::endl;

		pointer[1] = &arr[size];
		std::cout << *pointer[1] << std::endl;

		pointer[2] = &arr[(size * 2)];
		std::cout << *pointer[2] << std::endl;
	}
	
	void printArr()
	{
		
		int *ptr = &arr[0];
		for (int i = 0; i < size; ++i)
			std::cout << *ptr++ << std::endl;

		ptr = &arr[(size)];
		for (int i = 0; i < size; ++i)
			std::cout << *ptr++ << std::endl;

		ptr = &arr[(size) * 2];
		for (int i = 0; i < size; ++i)
			std::cout << *ptr++ << std::endl;
	}

	void pushAlt(int stackNumber, int data)
	{
		if (intPointer[stackNumber] + 1 >= size)
			return; //Break, exception, last element
		else 
		{
			++intPointer[stackNumber];
			arr[topOfStack(stackNumber)] = data;
		}

	}

	void popAlt(int stackNumber)
	{
		if (intPointer[stackNumber] != -1)
		{
			arr[topOfStack(stackNumber)] = 0;
			--intPointer[stackNumber];
		}
		else
			return; //break, no more elements

	}

	int topAlt(int stackNumber)
	{
		if (intPointer[stackNumber] != -1)
		{
			return arr[topOfStack(stackNumber)];
		}
		return -1;
	}

	int topOfStack(int stackNumber)
	{
		return stackNumber * size + intPointer[stackNumber];
	}

	void push(int stackNumber, int data)
	{
		if (pointer[stackNumber] < &arr[size * 3])
			*(pointer[stackNumber])++ = data;
	}

	void pop(int stackNumber)
	{
		if (pointer[stackNumber] > &arr[stackNumber * size]) 
		{
			--pointer[stackNumber];
			*pointer[stackNumber] = 0;
		}
	}

	int top(int stackNumber) {
		int *ptr = pointer[stackNumber];
		if (ptr > &arr[0])
			return *(--ptr);
		else return *ptr;
	}


};

void stackAndQueues::taskOne()
{
	ArrayFixedSizeThreeStack *st = new ArrayFixedSizeThreeStack(100);
	std::cout << "------------" << std::endl;
	for (int i = 0; i < 300; ++i)
	{
		st->push(i % 3, i);
	}

	st->printArr();

	for (int i = 0; i < 300; ++i)
	{
		std::cout << st->top(i % 3) << std::endl;
		st->pop(i % 3);
		std::cout << st->top(i % 3) << std::endl;
		std::cout << "------------" << std::endl;
	}

	st->printArr();

	for (int i = 0; i < 300; ++i)
		st->push(i % 3, i);
	st->printArr();

	for (int i = 0; i < 300; ++i)
	{
		std::cout << st->top(i % 3) << std::endl;
		st->pop(i % 3);
		std::cout << st->top(i % 3) << std::endl;
		std::cout << "------------" << std::endl;
	}
	

}



void stackAndQueues::taskTwo()
{
	myStack *stack = new myStack();
	stack->pushWithMin(5);
	stack->pushWithMin(1);
	stack->pushWithMin(-3);
	stack->popWithMin();
	stack->pushWithMin(3);
	stack->pushWithMin(0);
	stack->popWithMin();
	std::cout << stack->min.getMin() << std::endl;
	
}

class SetOfStacks {
private:
	std::vector<std::stack<int>*> stacks;
	int capacity = 5;

	std::stack<int>* getLastStack() {
		if (!stacks.empty())
			return stacks[stacks.size() - 1];
		return nullptr;
	}

public:
	void print() {
		for (auto st : stacks)
		{
			std::cout << st->size() << std::endl;
		}
	}
	void push(int value)
	{
		std::stack<int>* stack = getLastStack();
		if (stack != nullptr && (stack->size() + 1) <= capacity)
		{
			stack->push(value);
		}
		else {
			std::cout << "new stack" << std::endl;
			stack = new std::stack<int>();
			stack->push(value);
			stacks.push_back(stack);
		}
	}

	int pop()
	{
		std::stack<int>* stack = getLastStack();
		int top = stack->top();
		stack->pop();

		if (stack->empty())
		{
			delete stack;
			stacks.pop_back();
			std::cout << "delete stack" << std::endl;
		}

		return top;
	}

	void moveLeft(int index, std::stack<int>* stack)
	{
		int offset = index + 1;
		for (int i = offset; i < stacks.size(); ++i)
		{
			auto act = stacks[i];
			std::stack<int> buf;
			while (!act->empty())
			{
				buf.push(act->top());
				act->pop();
			}

			stack->push(buf.top());
			buf.pop();
			stack = act;
			while (!buf.empty())
			{
				act->push(buf.top());
				buf.pop();
			}
		}
	}

	void popAt(int index)
	{
		auto stack = stacks.at(index);
		stack->pop();
		if (!stack->empty())
			moveLeft(index, stack);
		else
		{
			delete stack;
			stacks.pop_back();
		}

	}
};

void stackAndQueues::taskThree()
{
	SetOfStacks set;
	for (int i = 0; i < 15; ++i) set.push(i);
	//set.print();
	set.popAt(0);
	set.popAt(1);
	set.popAt(2);
	set.popAt(2);
	set.popAt(2);
	for (int i = 0; i < 15 - 5; ++i) std::cout << set.pop() << std::endl;
}

typedef std::stack<int> Tower;
void moveTop(Tower* origin, Tower* destination)
{
	int top = origin->top();
	
	//if (destination->size() == 0 || top < destination->top())
	//{
		destination->push(top);
		origin->pop();
	//}
}

void printLine()
{
	std::cout << "-------------------" << std::endl;
}

std::vector<Tower*> towers;
void printTower(int index)
{
	std::cout << "Tower #" << index + 1 << std::endl;
	std::vector<int> buf;
	int size = towers[index]->size();
	for (int i = 0; i < size; ++i)
	{
		std::cout << towers[index]->top() << "\t";
		buf.push_back(towers[index]->top());
		towers[index]->pop();
	}
	std::cout << std::endl;

	for (int i = buf.size() - 1; i >= 0; --i)
	{
		towers[index]->push(buf[i]);
	}
}

void moveDisks(int n, Tower* origin, Tower* destination, Tower* buffer, int &i)
{
	if (n <= 0) return;

	moveDisks(n - 1, origin, buffer, destination, i);

	moveTop(origin, destination);
	printTower(0);
	printTower(1);
	printTower(2);

	printLine();
	++i;

	moveDisks(n - 1, buffer, destination, origin, i);
}

void stackAndQueues::taskFour()
{
	for (int i = 0; i < 3; ++i)
	{
		Tower* newTower = new Tower();
		towers.push_back(newTower);
	}

	int HANOI_SIZE = 5;
	for (int i = HANOI_SIZE; i > 0; --i)
	{
		towers[0]->push(i);
	}

	/*printTower(0);
	printTower(1);
	printTower(2);
	printLine();*/

	int i = 0;
	moveDisks(HANOI_SIZE, towers[0], towers[2], towers[1], i);

	/*printTower(0);
	printTower(1);
	printTower(2);*/

	std::cout << "\n" << i << "\n";

}

class MyQ {
public:
	std::stack<int> st1;
	std::stack<int> st2;

	void push(int i)
	{
		if (st1.empty()) st1.push(i);
		else
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
			st2.push(i);

			while (!st2.empty())
			{
				st1.push(st2.top());
				st2.pop();
			}
		}
	}

	int pop()
	{
		int top = st1.top();
		st1.pop();
		return top;
	}

	void pushNewest(int i)
	{
		st1.push(i);
	}

	void shiftStacks() 
	{
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
	}

	int popOldest()
	{
		shiftStacks();

		int top = st2.top();
		st2.pop();
		return top;
	}
};

void stackAndQueues::taskFive()
{
	MyQ q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	for (int i = 0; i < 4; ++i)
		std::cout << q.pop() << std::endl;

	q.pushNewest(1);
	q.pushNewest(2);
	q.pushNewest(3);
	q.pushNewest(4);
	for (int i = 0; i < 4; ++i)
		std::cout << q.popOldest() << std::endl;

}


int pop(std::stack<int> &st1)
{
	int top = st1.top();
	st1.pop();
	return top;
}

std::stack<int> sort(std::stack<int> st1)
{
	//pop push empty peek //only
	std::stack<int> st2;
	int buf;
	while (!st1.empty())
	{
		buf = pop(st1);
		while (!st2.empty() && st2.top() > buf)
		{
			st1.push(pop(st2));
		}
		st2.push(buf);
	}

	st1 = st2;
	int size = st2.size();
	for (int i = 0; i < size; ++i)
		std::cout << pop(st1) << "\t";
	return st2;

}
void stackAndQueues::taskSix()
{
	std::stack<int> st1;

	st1.push(3);
	st1.push(1);
	st1.push(2);
	st1.push(5);
	st1.push(3);
	st1.push(4);
	sort(st1);


}

class Animal {
private:
	std::string name;
	int order;
public:
	void setOrder(int order)
	{
		this->order = order;
	}

	Animal(std::string name) {
		this->name = name;
	};

	virtual ~Animal() {};

	bool isOlderThan(Animal *a)
	{
		return this->order < a->order;
	}

	int getOrder()
	{
		return this->order;
	}

	void printName() {
		std::cout << this->name << "\n";
	}

	std::string getName() {
		return this->name;
	}
};

class Dog : public Animal {
private:
public:
	Dog(std::string name) : Animal(name) {
	}
};

class Cat : public Animal {
public:
	Cat(std::string name) : Animal(name) {
	}
};



class Shelter {
private:
	NNode<Dog*> *dogs = new NNode<Dog*>();
	NNode<Cat*> *cats = new NNode<Cat*>();
	int order = 0;
public:
	Animal* dequeueAny() {
		if (dogs->data->isOlderThan(cats->data))
		{
			dogs->deleteNode(dogs, dogs->data);
			return dogs->data;
		}
		else
		{
			cats->deleteNode(cats, cats->data);
			return cats->data;
		}
	}

	Cat* dequeueCat() {
		cats->deleteNode(cats, cats->data);
		return cats->data;
	}

	Dog* dequeueDog() {
		dogs->deleteNode(dogs, dogs->data);
		return dogs->data;
	}

	void enqueue(Animal *a)
	{		
		a->setOrder(this->order);
		++this->order;
		//dogs.push_back((Dog) a);
		//else cats.push_back((Cat) a);

		if (typeid(*a) == typeid(Dog))
			//dogs.push_back(static_cast<Dog*>(&a));
			dogs->appendToTail(static_cast<Dog*>(a));
		else
			cats->appendToTail(static_cast<Cat*>(a));
	}
public:
};

void stackAndQueues::taskSeven()
{
	Shelter sh;
	Cat *cat = new Cat("c1");
	Dog *dog = new Dog("d1");

	Cat *cat1 = new Cat("c2");
	Dog *dog1 = new Dog("d2");
	
	Cat *cat2 = new Cat("c3");
	Dog *dog2 = new Dog("d3");
	sh.enqueue(cat);
	sh.enqueue(dog);
	sh.enqueue(cat1);
	sh.enqueue(dog1);
	sh.enqueue(cat2);
	sh.enqueue(dog2);
	std::cout << sh.dequeueAny() << std::endl;
	std::cout << sh.dequeueDog() << std::endl;
	//std::cout << sh.dequeueDog() << std::endl;
	//std::cout << sh.dequeueCat() << std::endl;
	//std::cout << sh.dequeueAny() << std::endl;
	//std::cout << sh.dequeueAny() << std::endl;

}
