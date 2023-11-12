#pragma once

#include <iostream>

int getSum(int a, int b)
{
	while (b != 0) {
		unsigned int tmp = (a & b);
		a = a ^ b;
		b = tmp << 1;
	}
	return a;
}

namespace get_sum
{

void run_tests()
{
    std::cout << getSum(2, 3);
    std::cout << "new num\n";
    std::cout << getSum(2, 2);
    std::cout << "new num\n";
    std::cout << getSum(20, 28);
}

}

/*
* Status: accepted
* Runtime: 2ms, Beats 54.07%
* Memory: 6.32 Mb, Beats 20.66%
*/
