#pragma once

#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include "support_func.hpp"

struct int_p
{
	int fst;
	int snd;
};

bool operator<(const int_p& left, const int_p& right)
{
	return left.fst < right.fst&& left.snd < right.snd;
}

bool operator==(const int_p& left, const int_p& right)
{
	return left.fst == right.fst && left.snd == right.snd;
}

template <>
struct std::hash<int_p>
{
	std::size_t operator()(const int_p& k) const
	{
		return ( ( std::hash<int>()( k.fst ) ^ ( std::hash<int>()( k.snd ) << 1 ) ) >> 1 );
	}
};

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::unordered_set< int_p > check;
	for ( int i = 0; i < nums.size(); i++ )
	{
		check.insert( int_p{ target - nums[ i ], i } );
	}
	for ( int i = 0; i < nums.size(); i++ )
	{
		int val = nums[ i ];
		auto find_it = std::find_if(check.begin(), check.end(), [&val, &i](const int_p& pp) mutable
		{
			return pp.fst == val && i != pp.snd;
		} );
		if ( find_it != check.end() )
		{
			return { i, find_it->snd };
		}
	}
	return { -1, -1 };
}

/*
* Status: accepted
* Runtime: 511ms, Beats 5.14%
* Memory: 12.98 Mb, Beats 5.85%
*/