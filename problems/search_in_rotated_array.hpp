#pragma once

#include <vector>
#include <iostream>

int bin_search(const std::vector<int>& nums, int target, int left, int right)
{
	if (left > right)
	{
		return -1;
	}
	int mid = ( left + right )/2;
	std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
	int cur_num = nums[mid];
	if (cur_num == target)
	{
		return mid;
	}
	if (cur_num > target)
	{
		return bin_search(nums, target, left, mid);
	}
	else
	{
		return bin_search(nums, target, mid + 1, right);
	}
}


int bin_search_modified(const std::vector<int>& nums, int target, int left, int right)
{
	if (left > right)
	{
		return -1;
	}
	if (nums[left] > nums[right])
	{

	}
	int mid = (left + right) / 2;
	std::cout << "[" << left << "," << mid << "," << right << "]" << std::endl;
	int cur_num = nums[mid];
	if (cur_num == target)
	{
		return mid;
	}
	if (cur_num > target)
	{
		return bin_search(nums, target, left, mid);
	}
	else
	{
		return bin_search(nums, target, mid + 1, right);
	}
}

int search(std::vector<int>& nums, int target)
{
	return bin_search( nums, target, 0, nums.size() - 1);
}