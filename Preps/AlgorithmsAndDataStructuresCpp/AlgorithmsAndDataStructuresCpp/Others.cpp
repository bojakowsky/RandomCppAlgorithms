#include "stdafx.h"
#include "Others.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <array>
#include <time.h>
#include <stack>
template<typename T>
void printContainer(T cont, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << cont[i] << " ";
	}
	std::cout << std::endl;
}

void split(const std::string &s, char delim, std::vector<std::string> &elems, bool skipEmpty = true)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		if (!skipEmpty)
			elems.push_back(item);
		else
		{
			if (!item.empty())
				elems.push_back(item);
		}
				
	}
}

std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

std::vector<std::string> split2(const std::string &s, std::string delim)
{
	std::string sbuf = s;
	std::vector<std::string> token;
	/*int pos = 0;
	while ((pos = sbuf.find(delim)) != std::string::npos) 
	{
		std::string buf = sbuf.substr(0, pos);
		if (!buf.empty)
			token.push_back(buf);
		sbuf.erase(0, pos + delim.length());
	}*/

	int start = 0;
	int end = sbuf.find(delim);
	while (end != std::string::npos)
	{
		std::string buf = sbuf.substr(start, end - start);
		if (!buf.empty())
			token.push_back(buf);
		start = end + delim.length();
		end = sbuf.find(delim, start);
	}

	return token;
}


std::vector<std::string> reverse(std::vector<std::string> sentence)
{
	int size = sentence.size();
	for (int i = 0; i < size / 2; ++i)
	{
		std::swap(sentence[i], sentence[size - 1 - i]);
	}

	return sentence;

}

std::string vecToString(std::vector<std::string> elements) 
{
	std::string str = "";
	for (int i = 0; i < elements.size(); ++i)
		str += elements[i] + " ";

	return str;
}

std::string Others::task1()
{
	// std::string sentence = "some very simple sentence.";
	std::string sentence = "some   very  simple sentence. hiho :).";
	std::cout << sentence << std::endl;

	std::vector<std::string> elements;
	// elements = split(sentence, ' ');
	elements = split2(sentence, " ");
	printContainer<std::vector<std::string>>(elements, elements.size());

	elements = reverse(elements);
	printContainer<std::vector<std::string>>(elements, elements.size());
	
	if (sentence.empty())
		std::cout << "Empty.";
	else if (sentence.size() == 1)
	{
		return elements[0];
	}
	else 
	{
		std::string result = vecToString(elements);
		std::cout << result << std::endl;
		return result;
	}
}

enum skipDelimRecursevily {
	yes = true,
	no = false
};

void traverseRow(std::vector<int> row, int p)
{
	if (p >= row.size()) return;
	std::cout << row[p] << " ";
	traverseRow(row, p + 1);
}

void traverse(std::vector<std::vector<int>> arr, int p)
{
	if (p < 0 || p >= arr.size()) return;

	std::vector<int> row = arr[p]; //getting row
	traverseRow(row, 0);
	traverse(arr, p + 1);
}

void traverse(std::vector<std::vector<int>> arr)
{
	traverse(arr, 0);
}

void Others::task2() 
{
	std::vector<std::vector<int>> arr = { {1,2,3}, {4,5,6}, {7,8,9} };
	traverse(arr);
}

bool isEven(int i, const std::vector<int> &arr)
{
	return arr[i] % 2 == 0;
}

void Others::task3a_move(std::vector<int> arr)
{
	std::vector<int> odd;
	std::vector<int> even;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (isEven(i, arr))
			odd.push_back(arr[i]);
		else even.push_back(arr[i]);
		
	}

	arr.clear();
	std::copy(odd.begin(), odd.end(), std::back_inserter(arr));
	std::copy(even.begin(), even.end(), std::back_inserter(arr));
	//printContainer(arr, arr.size());
}

int countEven(std::vector<int> arr) {
	int counter = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (isEven(i, arr)) ++counter;
	}
	return counter;
}

void mergeParity(std::vector<int> &arr, std::vector<int> &arr1, std::vector<int> &arr2)
{
	arr.clear();

	int i, j, k;
	i = j = k = 0;

	for (i = 0, j = 0, k = 0; i < arr1.size() && j < arr2.size(); ++k)
	{
		if (isEven(i, arr1))
		{
			arr.push_back(arr1[i]);
			++i;
		}
		else
		{
			arr.push_back(arr2[j]);
			++j;
		}
		++k;
	}

	while (i < arr1.size())
	{
		arr.push_back(arr1[i]);
		++i;
	}

	while (j < arr2.size())
	{
		arr.push_back(arr2[j]);
		++j;
	}

}

void mergeSortParity(std::vector<int> &arr)
{
	if (1 < arr.size())
	{
		int p = arr.size() / 2;
		auto arr1 = std::vector<int>(arr.begin(), arr.begin() + p);
		mergeSortParity(arr1);
		auto arr2 = std::vector<int>(arr.begin() + p, arr.end());
		mergeSortParity(arr2);
		mergeParity(arr, arr1, arr2);
	}
}


void findEvenFromEnd_Rec_Ref(const std::vector<int> &arr, int begin, int &end)
{
	if (end <= begin) {
		end = -1;
		return;
	}
	
	if (isEven(end, arr))
		return;

	findEvenFromEnd_Rec_Ref(arr, begin, --end);

}

int findEvenFromEnd_Rec_Ret(const std::vector<int> &arr, int begin, int end)
{
	if (end <= begin) return -1;

	if (isEven(end, arr))
		return end;

	findEvenFromEnd_Rec_Ret(arr, begin, --end);


}

int findEvenFromEnd_Iter_Ret(const std::vector<int> &arr, int begin, int end)
{
	while (end >= begin)
	{
		if (isEven(end, arr))
			return end;
		--end;
	}
	return -1;
}

void findEvenFromEnd_Iter_Ref(const std::vector<int> &arr, int begin, int &end)
{
	while (end >= begin)
	{
		if (isEven(end, arr))
		{
			return;
		}
		--end;
	}
	end = -1;
}

void Others::task3a_merge_parity(std::vector<int> arr)
{

	int size = arr.size();
	//printContainer(arr, size);
	//mergeSort(arr);
	//printContainer(arr, size);
	mergeSortParity(arr);
	//printContainer(arr, size);
}

void Others::task3b_recursive_ref(std::vector<int> arr)
{
	
	int size = arr.size();
	int begin = 0;
	int end = size - 1;
	while (end >= begin)
	{
		if (isEven(begin, arr))
			++begin;
		else
		{
			findEvenFromEnd_Rec_Ref(arr, begin, end);
			if (end != -1)
			{
				std::swap(arr[begin], arr[end]);
				--end;
				++begin;
			}
		}
	}
}

void Others::task3b_iter_ref(std::vector<int> arr)
{

	int size = arr.size();
	int begin = 0;
	int end = size - 1;
	while (end >= begin)
	{
		if (isEven(begin, arr))
			++begin;
		else
		{
			findEvenFromEnd_Iter_Ref(arr, begin, end);
			if (end != -1)
			{
				std::swap(arr[begin], arr[end]);
				--end;
				++begin;
			}
		}
	}
	//printContainer(arr, size);
}

void Others::task3b_recursive_return(std::vector<int> arr)
{

	int size = arr.size();
	int begin = 0;
	int end = size - 1;
	while (end >= begin)
	{
		if (isEven(begin, arr))
			++begin;
		else
		{
			end = findEvenFromEnd_Rec_Ret(arr, begin, end);
			
			if (end != -1)
			{
				std::swap(arr[begin], arr[end]);
				--end;
				++begin;
			}
		}
	}
}

void Others::task3b_iter_return(std::vector<int> arr)
{

	int size = arr.size();
	int begin = 0;
	int end = size - 1;
	while (end >= begin)
	{
		if (isEven(begin, arr))
			++begin;
		else
		{
			end = findEvenFromEnd_Iter_Ret(arr, begin, end);
			if (end != -1)
			{
				std::swap(arr[begin], arr[end]);
				--end;
				++begin;
			}
		}
	}
}


int simpleRecursion(int val)
{
	if (val >= 30) return -1;
	if (val == 20) return val;
	else simpleRecursion(++val);	// fine
	// else simpleRecursion(++val); // error
	
}
void Others::task4()

void Others::simpleTest()
{
	int a, b;
	a = 0;
	b = 10;
	while (b >= a)
	{
		b--;
		b = simpleRecursion(b);
		a++;
	}
	
	std::cout << a << " " << b << std::endl;
}

void mergeVectors(std::vector<int> &arr, std::vector<int> &arr1, std::vector<int> &arr2)
{
	arr.clear();

	int i, j, k;
	i = j = k = 0;

	for (i = 0, j = 0, k = 0; i < arr1.size() && j < arr2.size(); ++k)
	{
		if (arr1[i] <= arr2[j])
		{
			arr.push_back(arr1[i]);
			++i;
		}
		else
		{
			arr.push_back(arr2[j]);
			++j;
		}
		++k;
	}

	while (i < arr1.size())
	{
		arr.push_back(arr1[i]);
		++i;
	}

	while (j < arr2.size())
	{
		arr.push_back(arr2[j]);
		++j;
	}
}
void mergeSortVectors(std::vector<int> &arr)
{
	if (1 < arr.size())
	{
		int p = arr.size() / 2;
		auto arr1 = std::vector<int>(arr.begin(), arr.begin() + p);
		mergeSortVectors(arr1);
		auto arr2 = std::vector<int>(arr.begin() + p, arr.end());
		mergeSortVectors(arr2);
		mergeVectors(arr, arr1, arr2);
	}
}

void mergeDynamicArrays(int *arr, int size1, int size2) {
	int* temp = new int[size1 + size2];
	int ptr1 = 0, ptr2 = 0;

	while (ptr1 + ptr2 < size1 + size2) {
		if (ptr1 < size1 && arr[ptr1] <= arr[size1 + ptr2] || ptr1 < size1 && ptr2 >= size2)
			temp[ptr1 + ptr2] = arr[ptr1++];

		if (ptr2 < size2 && arr[size1 + ptr2] < arr[ptr1] || ptr2 < size2 && ptr1 >= size1)
			temp[ptr1 + ptr2] = arr[size1 + ptr2++];
	}

	for (int i = 0; i < size1 + size2; i++)
		arr[i] = temp[i];

	delete temp;
}
void mergeSortDynamicArrays(int *arr, int size) {
	// http://www.hellgeeks.com/merge-sort/
	if (size == 1)
		return;

	int size1 = size / 2, size2 = size - size1;
	mergeSortDynamicArrays(arr, size1);
	mergeSortDynamicArrays(arr + size1, size2);
	mergeDynamicArrays(arr, size1, size2);
}

void mergeOptimizedVectors(std::vector<int> &arr, int size1, int size2) {
	int* temp = new int[size1 + size2];
	int ptr1 = 0, ptr2 = 0;

	while (ptr1 + ptr2 < size1 + size2) {
		if (ptr1 < size1 && arr[ptr1] <= arr[size1 + ptr2] || ptr1 < size1 && ptr2 >= size2)
			temp[ptr1 + ptr2] = arr[ptr1++];

		if (ptr2 < size2 && arr[size1 + ptr2] < arr[ptr1] || ptr2 < size2 && ptr1 >= size1)
			temp[ptr1 + ptr2] = arr[size1 + ptr2++];
	}

	for (int i = 0; i < size1 + size2; i++)
		arr[i] = temp[i];

	delete temp;
}

void mergeSortOptimizedVectors(std::vector<int> &arr, int size) {
	
	if (size == 1)
		return;

	int size1 = size / 2, size2 = size - size1;
	mergeSortOptimizedVectors(std::vector<int>(arr.begin(), arr.begin() + size1), size1);
	mergeSortOptimizedVectors(std::vector<int>(arr.begin() + size1, arr.end()), size2);
	mergeOptimizedVectors(arr, size1, size2);
}



using namespace std;
void Others::task0_merge_arrays(int a[], int size)
{
	mergeSortDynamicArrays(a, size);

	//// Print the sorted array
	//cout << endl;
	//for (int i = 0; i < size; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
}

void Others::task0_merge_optimized_vectors(std::vector<int> arr)
{
	int size = arr.size();
	mergeSortOptimizedVectors(arr, size);
}

void Others::task0_merge_vectors(std::vector<int> arr, int size)
{
	mergeSortVectors(arr);
}

void Others::task4()
{
	int arr[] = { 1,2,5,3,6,4 };
	//stack, temp?

	for (int i = 0; i < 6; ++i)
	{

	}
}
