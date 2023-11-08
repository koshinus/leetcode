#pragma once
#include <vector>

std::vector<int> algo_with_division(std::vector<int>& nums)
{
	std::vector<int> res(nums.size(), 0);
	int null_pos = -1;
	int nulls_count = 0;
	int product_without_null = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			// We already have one null position -> all result arr will be 0
			if (null_pos != -1)
			{
				return res;
			}
			null_pos = i;
			continue;
		}
		product_without_null *= nums[i];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (null_pos == -1)
		{
			res[i] = product_without_null / nums[i];
			continue;
		}
		if (i == null_pos)
		{
			res[i] = product_without_null;
		}
	}
	return res;
}

// TODO: understand next two algos
std::vector<int> algo1_without_division(std::vector<int>& nums)
{
	std::vector<int> ans(nums.size(), 1);
	for (int i = 1; i < nums.size(); i++)                            // store prefix product
	{
		ans[i] = ans[i - 1] * nums[i - 1];
	}
	for (int i = nums.size() - 1, suffixProd = 1; i >= 0; i--)
	{
		ans[i] *= suffixProd;                                      // multiply stored prefix product with suffix product
		suffixProd *= nums[i];                                     // update suffix product
	}
	return ans;
}

std::vector<int> algo2_without_division(std::vector<int>& nums)
{
	std::vector<int> ans(size(nums), 1);
	for (int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++)
	{
		ans[i] *= pre;             // similar to prefix product being calculated in 1st loop of previous solution
		pre *= nums[i];
		ans[n - 1 - i] *= suf;         // similar to suffix product being calculated in 2nd loop of previous solution
		suf *= nums[n - 1 - i];
	}
	return ans;
}

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
	return algo_with_division(nums);
}


/*
* Status: accepted
* Runtime: 59ms, Beats 5.76%
* Memory: 24.36 Mb, Beats 24.36%
*/