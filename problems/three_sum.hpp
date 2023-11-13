#pragma once

#include <vector>
#include <set>

struct int_triple
{
	int fst;
	int snd;
	int thd;
};

bool operator==(const int_triple& left, const int_triple& right)
{
	return left.fst == right.fst && left.snd == right.snd && left.thd == right.thd;
}

template <>
struct std::hash<int_triple>
{
	std::size_t operator()(const int_triple& k) const
	{
		return ((std::hash<int>()(k.fst) ^ (std::hash<int>()(k.snd) << 1) ^ (std::hash<int>()(k.thd) << 1)) >> 1);
	}
};

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
	std::set<int_triple> 
}