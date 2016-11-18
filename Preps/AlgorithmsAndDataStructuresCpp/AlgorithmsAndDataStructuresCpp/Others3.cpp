#include "stdafx.h"
#include "Others3.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

void spl(const std::string &s, char delim, std::vector<std::string> &elems, bool skipEmpty = true)
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

double strToDouble(std::string str)
{
	std::vector<std::string> buf;
	spl(str, '.', buf);

	double res = 0;
	double multiplier = 1;
	double precision = 0;
	if (buf.size() == 0) throw std::length_error("Given string is empty");
	if (buf.size() == 1 || buf.size() == 2)
	{
		auto s = buf[0];
		int begin = s[0] == '-' ? 1 : 0;
		for (int i = s.length() - 1; i >= begin; --i)
		{
			int val = s[i] - '0';
			if (val >= 0 && val <= 9)
			{
				res += val * multiplier;
				multiplier *= 10;
			}
		}
		
		if (buf.size() == 2)
		{
			s = buf[1];
			multiplier = 1;

			for (int i = s.length() - 1; i >= 0; --i)
			{
				int val = s[i] - '0';
				if (val >= 0 && val <= 9)
				{
					precision += val * multiplier;
					multiplier *= 10;
				}
			}
			//multiplier *= 10;
			res = res + (precision / multiplier);
		}
		return begin == 1 ? -res : res;
	}
	else throw std::exception("String is malformed");
}

void Others3::task1()
{
	//std::vector<std::string> v = { "-12.5", "5.3", "5.1f", "-5e10", "0e10", "2.2e2" };
	std::vector<std::string> v = { "-12.5", "5.3", "5.12345", "-32.123", "11.334411", "0.123", "0.0001" };
	double res;
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << strToDouble(v[i]) << std::endl;
	}
}
