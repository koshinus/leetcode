#pragma once

#include <vector>
#include <algorithm>
#include "support_func.hpp"

void get_sum_with_previuos(std::vector<int>& max_sums, int cur_idx, const std::vector<int>& nums)
{
	if (cur_idx == 0)
	{
		max_sums[0] = nums[0];
		return;
	}
	int cur_val = nums[cur_idx];
	int sum = max_sums[cur_idx - 1] + cur_val;
	if (sum >= 0)
	{
		max_sums[cur_idx] = sum;
	}
}

int maxSubArray(std::vector<int>& nums)
{
	std::vector<int> max_sums(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++)
	{
		get_sum_with_previuos(max_sums, i, nums);
	}
	support::print_vec(max_sums);
	int max_sum = *std::max_element( max_sums.begin(), max_sums.end() );
	return (max_sum > 0) ? max_sum : *std::max_element(nums.begin(), nums.end());
}