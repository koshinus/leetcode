#pragma once

#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums)
{
	int res = 0;
	int nums_size = nums.size();
	for (int i = 0; i < nums_size; i++)
	{
		res ^= nums[i];
		res ^= i;
	}
	res ^= nums_size;
	return res;
}


/*
* Status: accepted
* Runtime: 7ms, Beats 98.21%
* Memory: 18.3 Mb, Beats 36.78%
*/