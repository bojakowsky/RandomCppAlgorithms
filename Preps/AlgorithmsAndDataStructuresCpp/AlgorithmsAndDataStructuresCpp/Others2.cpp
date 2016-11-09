#include "stdafx.h"
#include "Others2.h"
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
#include <fstream>
#include <locale>
#include <codecvt>
#include <fcntl.h>
#include <io.h>
using namespace std;
void Others2::task1()
{
	locale::global(locale("Polish_Poland.1250"));
	//Spanish_Spain.1252
	//Chinese_China.936
	//https://docs.moodle.org/dev/Table_of_locales

	//read 1000chars from file
	wchar_t ch;
	wifstream fin;
	fin.open("file2.txt");
	if (!fin.is_open())
		return;

	//fin.imbue(locale(fin.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>())); // utf-8
	fin.imbue(locale(fin.getloc(), new codecvt_utf16<wchar_t, 0x10ffff, consume_header>())); // unicode
	int i = 0; int limit = 1000;
	while (fin >> noskipws >> ch) {
		wcout << ch; 
		
		if (i == limit) break;
		++i;
	}

	fin.close();

}

int fib( int n)
{
	if (n == 0 || n == 1) return n;

	return fib(n - 1) + fib(n - 2);
}

int fibExpanded(int n)
{
	if (n < 0) return 0;
	if (n == 0 || n == 1) return 1;

	return fibExpanded(n - 1) + fibExpanded(n - 2) + fibExpanded(n-3);
}

int fibExpanded1(int n)
{
	if (n < 0) return 0;
	if (n == 0 || n == 1) return 1;

	return fibExpanded1(n - 1) + fibExpanded1(n - 4);
}

int fibIter(int n)
{
	if (n == 0 || n == 1) return n;
	
	int f0 = 0;
	int f1 = 1;

	int sum = 0;

	int i = 2;
	for (i; i <= n; ++i)
	{
		sum = f0 + f1;
		f0 = f1;
		f1 = sum;
	}

	return sum;
}

void Others2::task2()
{
	//Given n amount of steps, how many different ways can you go up those steps?  
	std::cout << fib(4);
	std::cout << fibIter(4);
	std::cout << fibExpanded(4);
	std::cout << fibExpanded1(3);

}

class LLnode
{
public:
	LLnode *next = nullptr;
	LLnode *prev = nullptr;
	int val;

	LLnode(int val) {
		this->val = val;
	}
};

class LL
{
public:
	LLnode *root = nullptr;

	void add(int val)
	{
		if (root == nullptr)
		{
			root = new LLnode(val);
			return;
		}

		LLnode *node = root;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		
		node->next = new LLnode(val);
		node->next->prev = node;
	}

	void lastPointFirst()
	{
		if (root == nullptr)
		{
			return;
		}

		LLnode *node = root;
		while (node->next != nullptr)
		{
			node = node->next;
		}

		node->next = root;
	}

	void print()
	{
		LLnode *node = root;
		while (node != nullptr)
		{
			std::cout << node->val << " " << std::endl;
			node = node->next;
		}
	}

	void print_backwards()
	{
		LLnode *node = root;
		while (node->next != nullptr)
			node = node->next;
		
		while (node->prev != nullptr)
		{
			std::cout << node->val << " " << std::endl;
			node = node->prev;
		}
		
	}

	float find_median()
	{
		LLnode *n1 = root;
		if (n1->next == n1) return n1->val;

		LLnode *n2 = root;
		if (n2->next->next == n2) return ((n2->next->val + n2->next->next->val) / 2);

		// n1 = not changing
		n2 = n2->next;

		while (n2->next != root && n2 != root)
		{
			n2 = n2->next->next;
			n1 = n1->next;
		}
		if (n2 == root)
			return n1->val;
		else
			return (n1->val + n1->next->val) / 2.0;
	}
};

void Others2::task3()
{
	//Implement a function that insert a node into a doubly linked list
	std::cout << std::endl;
	LL l;
	l.add(3); l.add(5); l.add(6); l.add(1); l.add(7);
	l.print();
	l.print_backwards();
}

void Others2::task4()
{
	//Given a char array, reverse each space delimited word in place using 3 pointers and a temporary character. 
	char arr[] = { "alx ma kota kot ma ale. \0"};
	char *beg, *end, *delim;
	beg = end = delim = arr;
	char buf = -1;
	while (*beg != '\0')
	{
		while (*delim != ' ' && *delim != '\0')
		{
			++delim;
			if (*delim != ' ')
				++end;
		}

		while (beg <= end)
		{
			//swap
			buf = *beg;
			*beg = *end;
			*end = buf;
			++beg; --end;
		}

		if (*delim == '\0')
			break;

		++delim;
		beg = delim;
		end = beg;
	}

	std::cout << arr << std::endl;

}

void Others2::task5()
{
	//How would you find the median in a sorted circularly linked list given a first node
	LL l;
	l.add(1); l.add(2); l.add(3); l.add(4); l.add(5); l.add(6); l.add(7); l.add(8);
	l.add(9);
	l.lastPointFirst();
	std::cout << std::fixed << (float)l.find_median() << std::endl;

}

void Others2::task6()
{
	//How would you find the median in a sorted circularly linked list given a RANDOM node
	//similar way that task 5, u can find the begining (find the smallest value) and go to the end of a loop to get all elements (size)
	//or find the beginning and approach the same way as above in task 5.
}

void Others2::task7()
{
	//permutations
	std::vector<int> arr = { 3, 5, 1 };
	
	
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
		for (int j = 0; j < arr.size(); ++j)
		{
			if (i == j) continue;
			std::cout << arr[j] << " ";
		}std::cout << std::endl;
	}

	std::reverse(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
		for (int j = 0; j < arr.size(); ++j)
		{
			if (i == j) continue;
			std::cout << arr[j] << " ";
		}std::cout << std::endl;
	}
}

int divAndConquerModif(std::vector<int> arr, int l, int r, int min)
{
	//tbd //to be done
	if (r <= l) return min;
	int mid = (l + r) / 2;
	if (arr[l] <= arr[mid])
		if (arr[l] <= min && arr[mid] >= min)
		{
			divAndConquerModif(arr, l, mid - 1, min);
		}
		else
		{
			divAndConquerModif(arr, mid + 1, r, min);
		}
			
	else
	{
		if (arr[mid] <= min && arr[r] >= min)
		{
			divAndConquerModif(arr, mid + 1, r, min);
		}
		else
		{
			divAndConquerModif(arr, l, mid - 1, min);
		}
	}
		
	return min;

}

void Others2::task8()
{
	//Searching a number in a rotated sorted Array
	//O(log(n)) divde and conquer
	//	6 7 8 1 2 3 4 5  
	//	^       ^     ^ 

	//	6 7 8 1 2  
	//	^   ^   ^
	//An sorted array is shifted.How to detect how much it has been shifted ?
	//std::vector<int> arr = { 3, 5, 1 }; 
	//std::vector<int> arr = { 5, 1, 3 };
	//std::vector<int> arr = { 3, 1, 5 };
	//std::vector<int> arr = { 3, 1, 5, 6, 7 };

	//O(n) solution
	//also O(n) solution if we add the same arr to the curr arr, and then find the sorted values matching original size like:
	//3, 5, (1, 3, 5), 1 => sequence of length 3 properly sorted, but takes 2*n memory;
	//std::vector<int> arr = { 5, 6, 7, 1, 3};
	std::vector<int> arr = { 3, 5, 6, 7, 1};
	
	int minIndex = 0;
	int minVal = 999;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] <= minVal)
		{
			minVal = arr[i];
			minIndex = i;
		}
	}

	int mid = arr.size() / 2;
	if (minIndex <= mid)
		std::cout << minIndex << std::endl;
	else
		std::cout << arr.size() - minIndex << std::endl;

	//divide n conquer
	int min = 1;
	//std::cout << divAndConquerModif(arr, 0, arr.size() - 1, min) << std::endl;
	//work on this //to be done //tbd 
}

void Others2::task9()
{
	std::string val = "321";
	int intVal = 0;
	int multiplier = 1;
	int begin = val[0] == '-' ? 1 : 0;
	for (int i = val.length() - 1; i >= begin; --i)
	{
		int digit = val[i] - '0';
		if (digit <= 9 && digit > 0)
		{
			intVal += digit * multiplier;
			multiplier *= 10;
		}
		else
		{
			intVal = -1;
			break;
		}
	}
	if (begin == 1)
		intVal *= -1;

	std::cout << intVal << std::endl;
}


bool isPrime(int n)
{
	if (n < 1) return false;
	if (n <= 3) return true;
	else
	{
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n % i == 0) return false;
		}
	}
	return true;
}

std::vector<int> generate(int n) {
	std::vector<int> result = std::vector<int>();
	if (n < 2) {
		return result;
	}

	// initialize the vector
	std::vector<bool> input(n + 1, true);

	int sqrtN = (int)sqrt(n);

	for (int i = 2; i <= sqrtN; i++) {
		if (!input[i]) {
			continue;
		}

		for (int j = i * i; j <= n; j += i) {
			input[j] = false;
		}
	}

	result.push_back(2);
	for (int i = 3; i <= n; i += 2) {
		if (input[i]) {
			result.push_back(i);
		}
	}

	return result;
}

void Others2::task10()
{
	std::cout << isPrime(1) << std::endl;
	std::cout << isPrime(2) << std::endl;
	std::cout << isPrime(3) << std::endl;
	std::cout << isPrime(4) << std::endl;
	std::cout << isPrime(5) << std::endl;
	std::cout << isPrime(6) << std::endl;
	std::cout << isPrime(7) << std::endl;
	std::cout << isPrime(8) << std::endl;
	std::cout << isPrime(9) << std::endl;

	auto vec = generate(100);
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
}


std::vector<int>  factorize(int n)
{
	int s = n;
	std::vector<int> factors;
	while (s % 2 == 0)
	{
		s /= 2;
		factors.push_back(2);
	}

	for (int i = 3; i <= sqrt(n)+1; i+=2)
	{
		while (s % i == 0)
		{
			factors.push_back(i);
			s /= i;
		}
	}
	return factors;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int gcditer1(int a, int b) {
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return b;
}

int gcditer2(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

//Multiplying matrix
//for (i = 0; i < r1; ++i)
//	for (j = 0; j < c2; ++j)
//		for (k = 0; k < c1; ++k)
//		{
//			mult[i][j] += a[i][k] * b[k][j];
//		}

void Others2::task11()
{
	std::cout << gcd(12, 8) << std::endl;
	std::cout << gcditer1(12, 8) << std::endl;
	std::cout << gcditer2(12, 8) << std::endl;

	std::cout << std::endl;

	//std::vector<int> factors = factorize(20);
	std::vector<int> factors = factorize(15485863);
	for (int i = 0; i < factors.size(); ++i)
		std::cout << factors[i] << " ";
}

//Fast modulo example
//int powermod(base, exponent, modulus) {
//	if (base < 1 || exponent < 0 || modulus < 1)
//		return -1
//
//		result = 1;
//	while (exponent > 0) {
//		if ((exponent % 2) == 1) {
//			result = (result * base) % modulus;
//		}
//		base = (base * base) % modulus;
//		exponent = floor(exponent / 2);
//	}
//	return result;
//}