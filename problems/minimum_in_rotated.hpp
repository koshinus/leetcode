#pragma once

#include <vector>

int get_start_in_rotated_array(std::vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;
	while (left < right && nums[left] > nums[right])
	{
		int mid = (left + right) / 2;
		//std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
		int mid_val = nums[mid];
		if (mid_val > nums[right])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int findMin(std::vector<int>& nums)
{
	return nums[get_start_in_rotated_array(nums)];
}

/*
* Status: accepted
* Runtime: 7ms, Beats 7.46%
* Memory: 10.40 Mb, Beats 52.7%
*/