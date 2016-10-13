#include "stdafx.h"
#include "Moderate.h"
#include <iostream>

namespace moderate {

	template <typename T> 
	void swapXOR(T &x, T &y)
	{
		//a = 101 // 5
		//b = 110 // 6
		//a = a ^ b; // 011
		//b = a ^ b; // 101 = b
		//a = a ^ b; // 110 = a

		x = x ^ y; 
		y = x ^ y;
		x = x ^ y;

		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "---" << std::endl;
	}

	void swapMATH(int &x, int &y)
	{
		//a = 5
		//b = 9
		//b = b - a = 4
		//a = a + b = 9
		//b = a - b = 5

		y = y - x;
		x = x + y;
		y = x - y;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "---" << std::endl;
	}

	void taskOne() {
		////Math time
		int x = 5;
		int y = 9;
		swapMATH(x, y);
		x = 9;
		y = 5;
		swapMATH(x, y);
		x = -3;
		y = 10;
		swapMATH(x, y);
		x = -1;
		y = -3;
		swapMATH(x, y);

		////Xor time
		x = 5;
		y = 9;
		swapXOR(x, y);
		x = 9;
		y = 5;
		swapXOR(x, y);
		x = -3;
		y = 10;
		swapXOR(x, y);
		x = -1;
		y = -3;
		swapXOR(x, y);
	}
}