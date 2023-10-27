#pragma once

#include <iostream>
#include "support_func.hpp"

int getSum(int a, int b)
{
	/*
	support::print_val_binary(a & b);
	support::print_val_binary(a | b);
	support::print_val_binary(a ^ b);
	support::print_val_binary((a ^ b) | (a & b));
	std::cout << std::endl;
	support::print_val_binary(~a & b);
	support::print_val_binary(~a | b);
	support::print_val_binary(~a ^ b);
	support::print_val_binary((a ^ b) | (a & b));
	std::cout << std::endl;
	support::print_val_binary(a & ~b);
	support::print_val_binary(a | ~b);
	support::print_val_binary(a ^ ~b);
	support::print_val_binary((a ^ b) | (a & b));
	std::cout << std::endl;
	support::print_val_binary(a + b);
	return a + b;
	*/

	while (b != 0) {
		unsigned int tmp = (a & b);
		a = a ^ b;
		b = tmp << 1;
	}
	return a;
}

/*
* Status: accepted
* Runtime: 2ms, Beats 54.07%
* Memory: 6.32 Mb, Beats 20.66%
*/