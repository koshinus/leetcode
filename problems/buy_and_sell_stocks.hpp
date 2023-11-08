#pragma once

#include <vector>

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

int maxProfit(std::vector<int>& prices)
{
	int max_profit = 0;
	int best_day_to_buy = -1, best_day_to_sell = prices.size() - 1;
	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (prices[i] <= prices[i + 1])
		{
			best_day_to_buy = i;
		}
	}
	if (best_day_to_buy == -1)
	{
		return 0;
	}
}