#pragma once

#include <vector>
#include <iostream>

int get_start_in_rotated_array1(std::vector<int>& nums)
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
	return nums[get_start_in_rotated_array1(nums)];
}

namespace find_min
{

void run_tests()
{
    std::vector<int> vec5{ 4,5,6,7,0,1,2 };
    std::cout << findMin(vec5) << "\n";
}

}


/*
* Status: accepted
* Runtime: 7ms, Beats 7.46%
* Memory: 10.40 Mb, Beats 52.7%
*/
