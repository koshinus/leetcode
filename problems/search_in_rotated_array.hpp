#pragma once

#include <vector>
#include <iostream>

int bin_search_recursive(const std::vector<int>& nums, int target, int left, int right)
{
	if (left > right)
	{
		return -1;
	}
	int mid = ( left + right )/2;
	//std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
	int cur_num = nums[mid];
	if (cur_num == target)
	{
		return mid;
	}
	if (cur_num > target)
	{
		return bin_search_recursive(nums, target, left, mid);
	}
	else
	{
		return bin_search_recursive(nums, target, mid + 1, right);
	}
}

int bin_search(const std::vector<int>& nums, int target, int start_left, int start_right)
{
	//int left = 0, right = nums.size() - 1;
	int left = start_left, right = start_right;
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;
	while (left < right)
	{
		int mid = (left + right) / 2;
		std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
		int cur_num = nums[mid];
		if (cur_num == target)
		{
			return mid;
		}
		if (cur_num > target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int get_start_in_rotated_array(std::vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;
	while (left < right && nums[left] > nums[right])
	{
		int mid = (left + right) / 2;
		std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
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

int search_for_small(std::vector<int>& nums, int target)
{
	if (nums.empty())
	{
		return -1;
	}
	if (nums.size() == 1)
	{
		return nums[0] == target ? 0 : -1;
	}
	if (nums.size() == 2)
	{
		if (nums[0] == target) return 0;
		return nums[1] == target ? 1 : -1;
	}
	if (nums.size() == 3)
	{
		if (nums[0] == target) return 0;
		if (nums[1] == target) return 1;
		if (nums[2] == target) return 2;
		return -1;
	}
}

int search(std::vector<int>& nums, int target)
{
	if (nums.size() < 4)
	{
		return search_for_small(nums, target);
	}
	int start = get_start_in_rotated_array(nums);
	std::cout << "Rotation start at " << start << "\n";
	if (start == 0)
	{
		return bin_search(nums, target, 0, nums.size());
	}
	int start_val = nums[start];
	int left_search_res = bin_search(nums, target, 0, start - 1);
	if (left_search_res != -1)
	{
		return left_search_res;
	}
	return bin_search(nums, target, start, nums.size());
}

/*
* Status: accepted
* Runtime: 0ms?, Beats 100%
* Memory: 11.42 Mb, Beats 28.16%
*/