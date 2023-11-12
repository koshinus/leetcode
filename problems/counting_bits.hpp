#pragma once

#include <vector>

#include "support_func.hpp"

int count_bits_for_number(int k)
{
	int res = 0;
	while (k > 0)
	{
		if ( ( k & 1 ) == 1)
		{
			res++;
		}
		k >>= 1;
	}
	return res;
}

std::vector<int> countBits(int n)
{
	std::vector<int> result;
	result.reserve( 10'000 );
	for ( int i = 0; i < ( n + 1 ); i++ )
	{
		result.emplace_back( count_bits_for_number( i ) );
	}
	return result;
}

namespace count_bits
{

void run_tests()
{
    support::print_vec( countBits( 5 ) );
}

}

/*
* Status: accepted
* Runtime: 7ms, Beats 25.5%
* Memory: 8.16 Mb, Beats 49.74%
*/
