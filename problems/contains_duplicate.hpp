#pragma once

#include <vector>
#include <unordered_set>

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

/*
* Status: accepted
* Runtime: 106ms, Beats 40.3%
* Memory: 71.65 Mb, Beats 20.04%
*/