#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#include <limits>
#include <algorithm>
#include <math.h>
#include <map>

//std::string subtract(std::string s1, std::string s2)
//{
//	//std::string res = "";
//	int hours1 = std::atoi(s1.substr(0, 2).c_str());
//	int mins1 = std::atoi(s1.substr(3, 2).c_str());
//	int secs1 = std::atoi(s1.substr(6, 2).c_str());
//
//	int hours2 = std::atoi(s2.substr(0, 2).c_str());
//	int mins2 = std::atoi(s2.substr(3, 2).c_str());
//	int secs2 = std::atoi(s2.substr(6, 2).c_str());
//
//	/*
//	int h = hours1 - hours2;
//	int m = mins1 - mins2;
//	int s = secs1 - secs2;
//	if (s < 0)
//	{
//		--m;
//		s = 60 + s;
//	}
//
//	if (m < 0)
//	{
//		--h;
//		m = 60 + m;
//	}
//
//	std::string hour = "0" + std::to_string(h);
//	std::string mins = m < 10 ? "0" + std::to_string(m) : std::to_string(m);
//	std::string secs = s < 10 ? "0" + std::to_string(s) : std::to_string(s);
//
//	res = hour + ":" + mins + ":" + secs;*/
//	//return res;
//}

template <typename T>
void p(T d)
{
	std::cout << d << std::endl;
}

int strToSec(std::string s)
{
	int hours1 = atoi(s.substr(0, 2).c_str());
	int mins1 = atoi(s.substr(3, 2).c_str());
	int secs1 = atoi(s.substr(6, 2).c_str());

	return hours1 * 3600 + mins1 * 60 + secs1;
}

void negativeSplitTask()
{
	int n;
	std::cin >> n;

	int negativeSplit = 0;
	int negativeSplitPassed = 0;

	int others = 0;
	int othersPassed = 0;
	n++;

	while (n--)
	{
		std::string time;
		std::getline(std::cin, time);

		if (time == " " || time == "") continue;
		std::vector<std::string> splitTime;
		int last = 0;
		for (int i = 0; i < time.size(); ++i)
		{
			if (time[i] == ' ')
			{
				splitTime.push_back(time.substr(last, i - last));
				if (splitTime.back() == "")
					splitTime.pop_back();
				last = i + 1;
			}
		}
		splitTime.push_back(time.substr(last, 9));

		int s0 = strToSec(splitTime[0]);
		int s1 = strToSec(splitTime[1]);
		int s2 = strToSec(splitTime[2]);
		int s3 = strToSec(splitTime[3]);

		int s4 = strToSec(splitTime[4]);
		int s5 = strToSec(splitTime[5]);

		int s10 = s1 - s0;
		int s21 = s2 - s1;
		int s32 = s3 - s2;
		//p(s0);
		//p(s10);
		//p(s21);
		//p(s32);

		//negative split
		if (s0 > s32 && s10 <= s0 && s21 <= s10 && s32 <= s21)
		{
			++negativeSplit;
			if (s4 <= s5)
				++negativeSplitPassed;
		}
		//positive split
		//constant
		else
		{
			++others;
			if (s4 <= s5)
				++othersPassed;
		}

	}

	std::cout << negativeSplitPassed << "/" << negativeSplit << " " << othersPassed << "/" << others;
	int breakcin;
	std::cin >> breakcin;
}

bool clausuleAND(std::vector<int*> *vec, std::vector<int*> vars)
{
	if (vec->empty()) return false;

	int res = 0;
	int sum = 0;
	for (int i = 0; i < vec->size(); ++i)
	{
		if (*vec->at(i) < 0 && vec->at(i) < vars[100])
		{
			*vars.at(std::abs(*vec->at(i)) + 99) *= -1;
			*vec->at(i) *= -1;
		}
		else if (*vec->at(i) < 0)
		{
			*vec->at(i) *= -1;
			*vars.at(*vec->at(i) - 1) *= -1;
		}

		sum += std::abs(*vec->at(i));
	}

	for (int i = 0; i < vec->size(); ++i)
	{
		res += *vec->at(i);
	}

	return res == sum;
}

int task2()
{
	int t;
	std::cin >> t;

	while
		(t--)
	{
		int n, k;
		std::cin >> n >> k;

		bool uniques;
		bool single = false;
		for (int i = 0; i < n; ++i)
		{
			uniques = true;
			int d;
			std::cin >> d;

			std::vector<int> set;
			for (int j = 0; j < d; ++j)
			{
				int l;
				std::cin >> l;

				if (single)
				{
					set.clear();
					continue;
				}

				if (!uniques)
				{
					continue;
				}

				int size = set.size();
				int notL = l * (-1);
				set.push_back(l);
				for (int i = 0; i < size; ++i)
				{
					if (set[i] == notL)
					{
						set.clear();
						uniques = false;
						break;
					}
				}

			}

			if (uniques)
				single = true;
		}
		if (!single)
			std::cout << "NIE" << std::endl;
		else
			std::cout << "TAK" << std::endl;
	}
	return 0;
}

//test cases
//3 5 3 // 9 = CCC, BBB, CBBB, BBBC, CCCC, CCBBB, CBBBC, BBBCC, CCCCC
//3 4 2 // 8 = CBB, BBC, CCC, BBCC, CBBC, CCBB, CCCC, BBBB
//5 5 5 // 2
//3 4 3 // 5 = CCC, BBB, CBBB, BBBC, CCCC
//1 4 1 // 24
//1 2 1 // 6
//2 2 1 // 4

void task3()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int a, b, k;
		std::cin >> a >> b >> k;
		int count = 0;
		int s = a;
		while (s <= b)
		{
			//all shifts
			int tempK = k;
			int sk = s - tempK + 1;
			while (sk >= 0)
			{
				count += s - tempK + 1;
				tempK += k;
				sk = s - tempK;
			}
			//only blacks
			count += 1;
			s++;
		}

		//while tbc...
		std::cout << count << std::endl;

	}

}

class PermGraph
{
public:
	int val;
	std::vector<PermGraph*> vals;
};

int countHelper(PermGraph* graph, int length, int end)
{
	if (length == end)
		return 1;

	int h = 0;

	int le = end - length;
	for (int i = 0; i < graph->vals.size(); ++i)
	{
		if (graph->vals.size() >= le)
			if (graph->val > graph->vals[i]->val)
				h += countHelper(graph->vals[i], length + 1, end);
	}

	return h;
}

int countPaths(std::vector<PermGraph*> graphs, int length)
{
	int h = 0;
	int len = length - 1;
	for (int i = 0; i < graphs.size(); ++i)
	{
		if (graphs[i]->vals.size() >= len)
			h += countHelper(graphs[i], 1, length);
	}
	return h;
}

/*int c = 0;
int loopSize = vec.size() - k + 1;
for (int i = 1; i <= loopSize; ++i)
{
for (int j = i + 1;  j <= loopSize + 1; ++j)
{
for (int k = j + 1; k <= loopSize + 2; ++k) {
std::cout << vec[i - 1] << " " << vec[j - 1] << " " << vec[k - 1] << std::endl;
}
}
}*/

class Node
{
public:
	Node(int data)
	{
		this->data = data;
	}

	Node() {};

	Node *left = nullptr;
	Node *right = nullptr;

	int data;
};

class Bst
{
	Node *root = nullptr;

	Node* insert(Node *node, int data)
	{
		if (node == nullptr)
			node = new Node(data);

		else if (data <= node->data)
		{
			node->left = insert(node->left, data);
		}
		else
		{
			node->right = insert(node->right, data);
		}

		return node;
	}
};

template <typename T>
void pr(T d)
{
	std::cout << d << std::endl;
}

class DLLNode
{
public:
	std::string data;
	DLLNode *next = nullptr;
	DLLNode *prev = nullptr;
};

//double linked lists
class DLL {
public:
	DLLNode *root;
};

typedef std::set<std::string> Set;
typedef std::map<char, Set> Map;

//#include <iostream>
//#include <vector>
//#include <algorithm>

int test5()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> vec;
	std::vector<int> vecBuf;
	int count = 0;

	int x = 1;
	while (n--)
	{
		/*int x;
		std::cin >> x;*/
		//vec.push_back(line[i] - '0');
		vec.push_back(x);
		++x;
	}

	vecBuf = vec;
	std::sort(vecBuf.begin(), vecBuf.end());
	std::reverse(vecBuf.begin(), vecBuf.end());

	if (k == vec.size())
	{
		bool exist = true;
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i] != vecBuf[i])
			{
				exist = false;
				break;
			}
		}

		if (exist)
			std::cout << 1 << std::endl;
	}
	else if (k > vec.size())
		std::cout << 0 << std::endl;
	else
		//k < vec.size()
	{
		int n = 4;

		for (int i = 1; i <= n - 2; ++i) {
			for (int j = i + 1; i <= n - 1; ++j) {
				for (int k = j + 1; j <= n; ++k)
					std::cout << i << " " << j << " " << k << std::endl;
			}
		}

		int mod = pow(10, 9);
		//std::cout << (vec.size() - k + 1) % mod << std::endl;
		for (int i = 0; i < vec.size() - k + 1; ++i)
		{
			bool okay = true;
			for (int j = 0; j < k - 1; ++j)
			{
				//std::cout << vecBuf[j + i] << std::endl;
				//std::cout << vecBuf[j + i + 1] << std::endl;
				if (vecBuf[j + i] <= vecBuf[j + i + 1])
				{
					okay = false;
					break;
				}
			}
			//std::cout << std::endl;

			if (okay)
				count++;
		}

		std::cout << (count % mod) << std::endl;
	}

	return 0;
}

int test4()
{
	std::ios::sync_with_stdio(false);

	int n, k;
	//std::cin >> n >> k;
	n = 100000;
	k = 2;

	int mod = pow(10, 9);
	std::vector<PermGraph*> graphs(n);

	int s = 0;
	while (n--)
	{
		//int x;
		//std::cin >> x;
		int x = n;

		PermGraph *graph = new PermGraph();
		graph->val = x;
		graphs[s] = graph;

		s++;
	}

	for (int i = 0; i < s - 1; ++i)
	{
		for (int j = i + 1; j < s; ++j)
		{
			if (graphs[i]->val > graphs[j]->val)
				graphs[i]->vals.push_back(graphs[j]);
		}
	}

	std::cout << (countPaths(graphs, k) % mod) << std::endl;

	return 0;
}

int test1()
{
	std::ios::sync_with_stdio(false);

	int x, m;
	std::cin >> x >> m;
	Map map;
	while (x--)
	{
		std::string cmd;
		std::string val;
		std::cin >> cmd;
		std::cin >> val;

		//add b
		if (cmd[0] == 'a')
		{
			std::string buf = val;
			map.insert(Map::value_type(buf[0], Set()));
			map[buf[0]].insert(buf);
		}

		//remove b
		else if (cmd[0] == 'r')
		{
			std::string buf = val;
			map[buf[0]].erase(buf);
		}

		//list b
		else if (cmd[0] == 'l')
		{
			std::string buf = val;
			int count = 0;
			std::cout << buf << ":";
			int size = buf.size();
			int others = 0;
			for (std::string i : map[buf[0]])
			{
				if (count < m)
				{
					if (i.size() >= size)
					{
						if (i.substr(0, size) == buf) {
							std::cout << " " << i;
							++count;
						}
					}
				}
				else
				{
					if (i.size() >= size)
					{
						if (i.substr(0, size) == buf) {
							++others;
						}
					}
				}
			}
			if (others > 0)
				std::cout << " and " << others << " other(s)" << std::endl;
			else std::cout << std::endl;
		}
	}

	return 0;
}

int test2()
{
	/*1
	2 2
	2 1 - 2
	1 - 2*/
	int t;
	std::cin >> t;
	++t;

	while (t--)
	{
		int n, k;
		std::cin >> n >> k;
		std::vector<int*> vars;
		//0 - 99 < 0
		// 99 = -1
		// 98 = -2
		// 0 = -100
		for (int i = -1; i >= -100; --i)
		{
			vars.push_back(new int(i));
		}
		// 100 - 199 > 0
		// 100 = 1
		// 101 = 2
		// 199 = 100
		for (int i = 1; i <= 100; ++i)
		{
			vars.push_back(new int(i));
		}

		std::vector<std::vector<int*>*> clauses;

		for (int i = 0; i < n; ++i)
		{
			int d;
			std::cin >> d;
			clauses.push_back(new std::vector<int*>());
			for (int j = 0; j < d; ++j)
			{
				int l;
				std::cin >> l;
				if (l < 0)
				{
					clauses.back()->push_back(vars[std::abs(l) - 1]);
				}
				else
				{
					clauses.back()->push_back(vars[l + 99]);
				}

			}
		}

		bool yes = false;
		//for (std::vector<int*> *clause : clauses)
		for (int i = 0; i < clauses.size(); ++i)
		{
			if (clausuleAND(clauses[i], vars)) {
				std::cout << "TAK" << std::endl;
				yes = true;
				break;
			}
		}
		if (!yes)
			std::cout << "NIE" << std::endl;

		int vs = vars.size() - 1;
		for (int i = vs; i >= 0; --i)
		{
			delete vars[i];
			vars.pop_back();
		}


		int cls = clauses.size() - 1;
		for (int i = cls; i >= 0; --i)
		{
			delete clauses[i];
			clauses.pop_back();
		}

	}

	//int cinner;
	//std:: cin >> cinner;

	return 0;

}

int test3()
{
	std::ios::sync_with_stdio(false);

	int x, m;
	std::cin >> x >> m;
	Map map;
	while (x--)
	{
		std::string cmd;
		//std::getline(std::cin, cmd);
		std::cin >> cmd;
		//add b
		if (cmd[0] == 'a')
		{
			if (cmd.size() <= 4) continue;
			std::string buf = cmd.substr(4, buf.size() - 3);
			//pr(buf);

			map.insert(Map::value_type(buf[0], Set()));
			map[buf[0]].insert(buf);
		}

		//remove b
		else if (cmd[0] == 'r')
		{
			if (cmd.size() <= 7) continue;
			std::string buf = cmd.substr(7, buf.size() - 6);
			//pr(buf);
			map[buf[0]].erase(buf);
		}

		//list b
		else if (cmd[0] == 'l')
		{
			if (cmd.size() <= 5) continue;
			std::string buf = cmd.substr(5, buf.size() - 4);
			//pr(buf);
			int count = 0;
			std::cout << buf << ":";
			int size = buf.size();
			int others = 0;
			for (std::string i : map[buf[0]])
			{
				if (count < m)
				{
					if (i.size() >= size)
					{
						if (i.substr(0, size) == buf) {
							std::cout << " " << i;
							++count;
						}
					}
				}
				else
				{
					if (i.size() >= size)
					{
						if (i.substr(0, size) == buf) {
							++others;
						}
					}
				}
			}
			if (others > 0)
				std::cout << " and " << others << " other(s)" << std::endl;
			else std::cout << std::endl;
		}
	}

	return 0;
}

