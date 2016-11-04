#include "stdafx.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "ArraysAndStrings.h"
#include <sstream>
#include <bitset>
#include <algorithm>

namespace arraysAndString
{
	void mapExample() {
		std::cout << "-- Map Example --" << std::endl;
		std::map<int, int> map1 = { { 1, 5 },{ 2, 6 } };
		std::cout << "Key '1' value: " << map1[1] << std::endl;
		std::map<char, int> map = { {'a', 5}, {'b', 6 } };
		map.insert(std::pair<char, int>('c', 5));
		map.insert(std::pair<char, int>('d', 6));
		map['b'] = 4;
		map['a'] = 3;
		map.insert(std::pair<char, int>('a', 5));
		map.insert(std::pair<char, int>('b', 5));
		map.insert(std::pair<char, int>('e', 2));
		std::map<char, int>::iterator it;
		for (it = map.begin(); it != map.end(); ++it) {
			std::cout << it->first << " -- " << it->second << std::endl;
		}

		std::cout << "Key 'a' value: " << map['a'] << std::endl;
		std::cout << "===" << std::endl;

		
	}

	void setExample() {
		std::cout << "-- Set Example --" << std::endl;
		std::set<int> set;
		set.insert(3);
		set.insert(4);
		set.insert(5);
		set.insert(3);
		set.insert(2);
		std::set<int>::iterator it;
		for (it = set.begin(); it != set.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << "Set 'begin' value: " << *set.begin() << std::endl;
		std::cout << "===" << std::endl;
	}

	void unorderedMapExample() {
		std::cout << "-- Unordered Map Example --" << std::endl;
		std::unordered_map<char, int> unorderedMap;

		unorderedMap.insert(std::pair<char, int>('c', 5));
		unorderedMap.insert(std::pair<char, int>('d', 6));
		unorderedMap.insert(std::pair<char, int>('e', 2));
		unorderedMap['a'] = 3;
		unorderedMap['b'] = 4;
		unorderedMap.insert(std::make_pair<char, int>('a', 5));
		unorderedMap.insert(std::pair<char, int>('b', 5));
		unorderedMap.insert(std::make_pair<char, int>('c', 5));

		/* Seems the same as as auto
		std::unordered_map<char, int>::iterator it;
		for (it = unorderedMap.begin(); it != unorderedMap.end(); ++it) {
			std::cout << it->first << " -- " << it->second << std::endl;
		}
		*/

		for (auto& x : unorderedMap)
			std::cout << x.first << " -- " << x.second << std::endl;

		std::cout << "Key 'a' value: " << unorderedMap['a'] << std::endl;
		std::cout << "===" << std::endl;

	}

	void multimapExample() {
		std::cout << "-- Multi-key Map Example --" << std::endl;
		std::multimap<char, int> multimap;

		multimap.insert(std::pair<char, int>('c', 5));
		multimap.insert(std::pair<char, int>('d', 6));
		multimap.insert(std::pair<char, int>('e', 2));
		// multimap['a'] = 3; syntax error
		// multimap['b'] = 4; syntax error
		multimap.insert(std::make_pair<char, int>('a', 5));
		multimap.insert(std::make_pair<char, int>('a', 3));
		multimap.insert(std::pair<char, int>('b', 5));
		multimap.insert(std::pair<char, int>('b', 4));
		multimap.insert(std::make_pair<char, int>('c', 5));

		for (auto& x : multimap)
			std::cout << x.first << " -- " << x.second << std::endl;

		std::cout << "Key 'a' value: " << std::endl;
		// std::multimap<char, int>::iterator it = multimap.find('c'); it will return iterator for all keys
		std::pair <std::multimap<char, int>::iterator, std::multimap<char, int>::iterator> ret;
		ret = multimap.equal_range('a');
		for (std::multimap<char, int>::iterator it = ret.first; it != ret.second; ++it) {
			std::cout << it->first << " -- " << it->second << std::endl;
		}

		std::cout << "===" << std::endl;

	}

	void unorderedSetExample() {
		std::cout << "-- Unordered Set Example --" << std::endl;
		std::unordered_set<int> unorderedSet;
		unorderedSet.insert(3);
		unorderedSet.insert(4);
		unorderedSet.insert(5);
		unorderedSet.insert(3);
		unorderedSet.insert(2);
		std::unordered_set<int>::iterator it;
		for (it = unorderedSet.begin(); it != unorderedSet.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << "Set 'begin' value: " << *unorderedSet.begin() << std::endl;
		std::cout << "===" << std::endl;

	}

	void arrayListExample() {
		std::cout << "-- ArrayList Example --" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(2);
		std::cout << "Vector 0 element value - " << vec[0] << std::endl;
	}

	void stringBuilderExample() {
		//However, C++ string are mutable, so copy isn't created everytime string is concatenated (in Java and C# strings are imutable)
		//Knowing above, we should not be worried to concatenate string using '+' operator, however we can also use 'std::ostringstream'
		std::cout << "-- StringBuilder Example --" << std::endl;
		std::string test = "123";
		test += "456";
		test += "789";
		std::cout << test << std::endl;

		std::ostringstream otest;
		otest << "123" << "456";
		otest << "789";
		std::string output = otest.str();
		std::cout << output << std::endl;
	}

	void taskOne() {
		std::unordered_set<char> set;
		//std::string str = "123456";
		std::string str = "1234562";
		for (unsigned int i = 0; i < str.length(); ++i)
		{
			if (!set.insert(str[i]).second) {
				std::cout << "False" << std::endl;
				return;
			}
		}
		std::cout << "True" << std::endl;
	}

	void taskOneOnBuff() {
		std::string str = "acglal";
		int checker = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			int val = str.at(i) - 'a';
			if ((checker & (1 << val)) > 0)
				std::cout << "False" << std::endl;
			checker |= (1 << val);
			std::cout << str.at(i) << " ";
			std::cout << std::bitset<16>(checker) << std::endl << std::endl;
		}
		std::cout << std::endl << "True" << std::endl;
	}

	void taskTwo(char *str) {
		std::cout << "original: " << str << std::endl;
		char *end = str;
		char *beg = str; // for reference
		while (*end)
			end++;
		--end;

		char tmp;
		while (str < end)
		{
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
		std::cout << "reversed #1: " << beg << std::endl;

		if (str) {
			std::string pstr(beg);
			for (int i = 0; i < pstr.length() / 2; ++i)
			{
				char tmp = pstr[i];
				pstr[i] = pstr[pstr.length() - i - 1];
				pstr[pstr.length() - i - 1] = tmp;
			}
			std::cout << "reversed #2: " << pstr << std::endl;
		}

		if (str) {
			std::string pstr(beg);
			std::reverse(pstr.begin(), pstr.end());
			std::cout << "reversed #3: " << pstr << std::endl;
		}

		std::string a = "abc";
		std::string b = "def";
		std::swap(a, b);
		std::cout << a << " " << b << std::endl;
	}

	void taskThree() {
		std::string a = "abac1";
		std::string b = "bcaa1";

		if (a.length() != b.length())
		{
			std::cout << "Not permutation" << std::endl;
			return;
		}

		//First	way
		std::sort(a.begin(), a.end());
		std::cout << a << std::endl;

		std::sort(b.begin(), b.end());
		std::cout << b << std::endl;

		if (a != b)
		{
			std::cout << "Not permutation" << std::endl;
			return;
		}
		std::cout << "Permutation" << std::endl;

		//Second way
		int letters[256];
		//std::fill(letters, letters + 256, 0);
		memset(letters, 0, sizeof(letters));
		for (char i : a)
		{
			int l = (int)i;
			++letters[l];
		}

		for (int i = 0; i < b.length(); ++i)
		{
			int l = (int)b[i];
			if (--letters[l] < 0)
			{
				std::cout << "Not permutation" << std::endl;
				return;
			}
		}
		std::cout << "Permuration" << std::endl;
	}

	void taskFour() {
		std::string str = "ala ma kota kot ma ale a a aa a ";
		int length = str.length();
		int spaces = 0;
		for (char s : str)
			if (s == ' ') ++spaces;
		str.insert(str.end(), spaces * 2, '%');
		int newLength = length + spaces * 2;
		str[newLength] = '\0';
		for (int i = length - 1; i >= 0; --i)
		{
			if (str[i] == ' ')
			{
				str[newLength - 1] = '0';
				str[newLength - 2] = '2';
				str[newLength - 3] = '%';
				newLength -= 3;
			}
			else
			{
				str[newLength - 1] = str[i];
				newLength -= 1;
			}
		}
		std::cout << str << std::endl;
	}

	void taskFive() {
		std::string str = "aabccccccaaa";
		std::string str2 = "";
		char last = str[0];
		int count = 1;
		for (int i = 1; i < str.length(); ++i)
		{
			if (str[i] != last) {
				str2 += last + std::to_string(count);
				last = str[i];
				count = 1;
			}
			else
				count++;
		}

		if (str.length() <= str2.length())
			std::cout << str << std::endl;
		else
			std::cout << str2 + last + std::to_string(count) << std::endl;
	}

	void rotate90(int **mat, int n)
	{
		for (int layer = 0; layer < n / 2; ++layer)
		{
			int first = layer;
			int last = n - 1 - layer;
			for (int i = first; i < last; ++i)
			{
				int offset = i - first;
				//save top
				int top = mat[first][i];
				//left -> top
				mat[first][i] = mat[last - offset][first];
				//down -> left
				mat[last - offset][first] = mat[last][last - offset];
				//right -> down
				mat[last][last - offset] = mat[i][last];
				// top -> right
				mat[i][last] = top;
			}
		}
	}

	void printArray(int **mat, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << mat[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "_____\n";
	}

	void taskSix() {
		/*int mat[5][5] = {
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14, 15},
			{16, 17, 18, 19, 20},
			{21, 22, 23, 24, 25}
		};*/
		int init = 1;
		int **mat = new int *[5];
		for (int i = 0; i < 5; ++i) {
			mat[i] = new int[5];
			for (int j = 0; j < 5; ++j)
				mat[i][j] = init++;
		}

		printArray(mat, 5);
		rotate90(mat, 5);
		printArray(mat, 5);
		for (int i = 0; i < 5; ++i)
			delete[] mat[i];
		delete[] mat;

	}

	typedef std::vector<std::vector<int>> matrix;

	void printVector(matrix mat)
	{
		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[0].size(); ++j)
			{
				std::cout << mat[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << "_________\n";
	}

	void setZeros(std::vector<std::vector<int>> &mat)
	{
		printVector(mat);
		int width = mat.size();
		int heigth = mat[0].size();
		std::cout << width << " " << heigth << std::endl;
		std::vector<bool> rows(width);
		std::vector<bool> cols(heigth);
		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[0].size(); ++j)
			{
				if (mat[i][j] == 0)
				{
					rows[i] = (true);
					cols[j] = (true);
				}
			}
		}

		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[0].size(); ++j)
			{
				if (rows[i] || cols[j])
					mat[i][j] = 0;
			}
		}
		printVector(mat);
	}

	int g = 0;
	int drawBit()
	{
		g++;
		if (g == 10) return 0;
		else return 1;
		//return rand() % 2;
	}

	void taskSeven()
	{
		std::vector<std::vector<int>> mat =
		{
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() },
			{ drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit(), drawBit() }
		};

		setZeros(mat);
		printVector(mat);
	}

	bool isSubstring(std::string str1, std::string str2)
	{
		for (int i = 0; i < str1.length(); ++i)
		{
			if (str1.substr(i, str2.length()) == str2)
				return true;
		}
		return false;
	}

	bool isRotation(std::string str1, std::string str2)
	{
		if (str1.length() == str2.length())
		{
			str1 += str1;
			//if (isSubstring(str1, str2))
			//	return true;
			//return false;
			return isSubstring(str1, str2);
		}
		return false;
	}

	void taskEight() {
		std::string str1 = "waterbottle";
		std::string str2 = "erbottlewat";
		if (isRotation(str1, str2))
			std::cout << "Is substring";
		else std::cout << "Not substring";
	}
}