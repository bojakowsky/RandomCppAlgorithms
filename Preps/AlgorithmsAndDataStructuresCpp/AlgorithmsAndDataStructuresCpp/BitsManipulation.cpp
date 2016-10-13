#include "stdafx.h"
#include "BitsManipulation.h"
#include <iostream>
#include <bitset>

void bitManipulation::test()
{
	int number = 65537*2;
	for (int i = 0; i < number; ++i)
	{
		/*if (number & number - 1)
		{
			std::cout << "Not a power of 2";
		}
		else
		{
			std::cout << (std::bitset<8>(number)) << std::endl;
			std::cout << (std::bitset<8>(number - 1)) << std::endl;
			std::cout << (number & number - 1) << std::endl;
			std::cout << "Power of 2";
		}*/
		if (!(i & i - 1))
		{
			std::cout << i << std::endl;
		}
	}
}
