#pragma once

#include <vector>
#include <unordered_set>
#include <iostream>

bool containsDuplicate(std::vector<int>& nums)
{
	std::unordered_set<int> nums_check;
	nums_check.reserve(nums.size());
	for (int i : nums)
	{
		nums_check.insert(i);
	}
	return nums_check.size() != nums.size();
}

// TODO: try write with O(1) space complexity, using xor operation


namespace contains_duplicates
{

void run_tests()
{
    std::vector<int> dups{ 1,2,3,4 };
    std::cout << containsDuplicate( dups ) << "\n";
}

}

/*
* Status: accepted
* Runtime: 106ms, Beats 40.3%
* Memory: 71.65 Mb, Beats 20.04%
*/
