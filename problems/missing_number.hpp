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

namespace missing_number
{

void run_tests()
{
    auto vec1 = std::vector<int>{ 3, 0, 1 };
    auto vec2 = std::vector<int>{ 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    std::cout << missingNumber(vec1) << " " << missingNumber(vec2);
}

}

/*
* Status: accepted
* Runtime: 7ms, Beats 98.21%
* Memory: 18.3 Mb, Beats 36.78%
*/
