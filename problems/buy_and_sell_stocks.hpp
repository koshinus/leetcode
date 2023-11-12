#pragma once

#include <vector>
#include <iostream>

struct precompute_info
{
	int max_val;
	int max_idx;
	int min_val;
	int min_idx;
	bool only_increasing;
	bool only_decreasing;
};

namespace max_profit
{

int quadratic_solution(const std::vector<int>& prices)
{
	int max_profit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i; j < prices.size(); j++)
		{
			max_profit = std::max(max_profit, prices[j] - prices[i]);
		}
	}
	return max_profit;
}

}

int get_index_of_the_first_increased_val(const std::vector<int>& prices)
{
	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (prices[i] < prices[i + 1])
		{
			return i;
		}
	}
	return -1;
}

void set_min_max(precompute_info& info, int cur_val, int cur_idx)
{
	if (info.max_val < cur_val)
	{
		info.max_val = cur_val;
		info.max_idx = cur_idx;
	}
	if (info.min_val > cur_val)
	{
		info.min_val = cur_val;
		info.min_idx = cur_idx;
	}
}

precompute_info precompute(const std::vector<int>& prices)
{
	precompute_info info{ prices[0], 0, prices[0], 0, true, true };
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int cur_val = prices[i], next_val = prices[i + 1];
		set_min_max( info, cur_val, i );
		if (cur_val < next_val)
		{
			info.only_decreasing = false;
		}
		if (cur_val > next_val)
		{
			info.only_increasing = false;
		}
	}
	int last = prices.size() - 1;
	set_min_max(info, prices[last], last);
	return info;
}

int algo_with_precomputed_info(const std::vector<int>& prices)
{
	if (prices.empty())
	{
		return 0;
	}
	auto info = precompute(prices);
	if (info.only_decreasing)
	{
		return 0;
	}
	if (info.only_increasing || info.max_idx > info.min_idx)
	{
		return info.max_val - info.min_val;
	}
	int max_val = 0;

	for (int i = info.min_idx; i < prices.size(); i++)
	{
		int cur_val = prices[i] - info.min_val;
		if (cur_val > max_val)
		{
			max_val = cur_val;
		}
	}
	for (int i = 0; i < info.max_idx; i++)
	{
		int cur_val = info.max_val - prices[i];
		if (cur_val > max_val)
		{
			max_val = cur_val;
		}
	}
	int new_min_idx = info.max_idx, new_min_val = prices[info.max_idx],
		new_max_idx = info.min_idx, new_max_val = prices[info.min_idx];
	for (int i = info.max_idx; i < info.min_idx; i++)
	{
		// TODO: write cycle with reassigning new max and min
	}
	return max_val;
}

int algo_with_ascending_segments(std::vector<int>& prices)
{
	// WRONG solution
	// Doesn't work with [7,1,5,3,6,4] for example: [1,5] will be segment,
	// but right answer is [1,5,3,6]
	int max_val = 0, incr_segment_start = 0;
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int segment_min = prices[incr_segment_start], next_val = prices[i + 1];
		std::cout << incr_segment_start << "->" << segment_min << ","
					<< i << "->" << prices[i] << ","
					<< i+1 << "->" << next_val << "\n";
		if (segment_min > next_val)
		{
			max_val = std::max( max_val, prices[ i ] - segment_min );
			incr_segment_start = i + 1;
		}
	}
	return max_val;
}

int kadane_algo()
{
	// TODO: write and understand
	return 0;
}

int maxProfit(std::vector<int>& prices)
{
	return algo_with_ascending_segments(prices);
	/*
	int best_day_to_buy = get_index_of_the_first_increased_val(prices),
		best_day_to_sell = prices.size() - 1;
	if (best_day_to_buy == -1)
	{
		return 0;
	}
	int max_profit = 0;
	*/
}


namespace max_profit
{

void run_tests()
{
    std::vector<int> vec{7,1,5,3,6,4};
    std::vector<int> vec1{ 7,6,4,3,1 };
    std::cout << maxProfit(vec) << "\n" << maxProfit(vec1);
}

}
