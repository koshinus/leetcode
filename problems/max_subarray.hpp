#pragma once

#include <vector>
#include <algorithm>
#include "support_func.hpp"

void get_sum_with_previuos(std::vector<int>& max_sums, int cur_idx, const std::vector<int>& nums)
{
	if (cur_idx == 0)
	{
		max_sums[0] = std::max( 0, nums[0] );
		return;
	}
	int cur_val = nums[cur_idx];
	int sum = max_sums[cur_idx - 1] + cur_val;
	if (sum >= 0)
	{
		max_sums[cur_idx] = sum;
	}
}

int solution_with_n_extra_space(const std::vector<int>& nums)
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

int solution_with_o1_extra_space(const std::vector<int>& nums)
{
    int max_in_nums = nums[0], max_sum = 0, cur_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur_val = nums[i];
        max_in_nums = std::max( max_in_nums, cur_val );
        cur_sum = std::max( cur_val + cur_sum, 0 );
        max_sum = std::max( max_sum, cur_sum );
    }
    return ( max_sum > 0 ) ? max_sum : max_in_nums;
}

int maxSubArray(std::vector<int>& nums)
{
    return solution_with_o1_extra_space(nums);
}

namespace max_subarray
{

void run_tests()
{
    std::vector<int> vec{ -2,1,-3,4,-1,2,1,-5,4 };
    std::vector<int> vec1{ 1 };
    std::vector<int> vec2{ 5,4,-1,7,8 };
    std::vector<int> vec3{ -2,1 };
    std::vector<int> vec4{ -3,-4,-5,-6,-7 };
    std::vector<int> vec5{ -1,1,2,1 };
    std::cout << maxSubArray(vec) << "\n"
              << maxSubArray(vec1) << "\n"
              << maxSubArray(vec2) << "\n"
              << maxSubArray(vec3) << "\n"
              << maxSubArray(vec4) << "\n"
              << maxSubArray(vec5) << "\n";
}

}

/*
* Status: accepted
* Runtime: 95ms, Beats 13.23%
* Memory: 68.06 Mb, Beats 51.81%
*/
