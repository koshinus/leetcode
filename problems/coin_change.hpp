#pragma once

#include <vector>
#include <iostream>
#include <map>

#include "support_func.hpp"

int bin_search(const std::vector<int>& nums, int target, int start_left, int start_right)
{
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

enum class ProcessResult
{
    FOUND,
    NOT_FOUND,
    COINS_BIGGER
};

ProcessResult processCurrentAmount(const std::vector<int>& coins, int amount)
{
    if (coins.front() > amount)
        return ProcessResult::COINS_BIGGER;
    int pos = bin_search(coins, amount, 0, coins.size() - 1);
    return pos == -1 ? ProcessResult::NOT_FOUND : ProcessResult::FOUND;
}

int fewestCoinNumber(const std::vector<int>& coins, int amount)
{
    if (int search_res = bin_search(coins, amount, 0, coins.size() - 1); search_res != -1)
    {
        return 1;
    }

    std::map<int, int> amounts_to_coins, std::map<int, int> currently_added;
    for (int coin : coins)
    {
        amounts_to_coins.insert( coin, 1 );
    }

    do
    {
        for (auto& p : amounts_to_coins)
        {

        }
        for (int coin : coins)
        {
        }
    } while (!currently_added.empty());
    return -1;
}

int coinChange(std::vector<int>& coins, int amount)
{
    if (amount == 0)
        return 0;
    if (coins.front() > amount)
        return -1;
    return fewestCoinNumber(coins, amount);
}

namespace coin_change
{
    void test1()
    {
        std::vector<int> vec{ 1,2,5 };
        int amount = 11;
        std::cout << coinChange(vec, amount) << "\n";
    }

    void test2()
    {
        std::vector<int> vec{ 2 };
        int amount = 3;
        std::cout << coinChange(vec, amount) << "\n";
    }

    void test3()
    {
        std::vector<int> vec{ 1 };
        int amount = 0;
        std::cout << coinChange(vec, amount) << "\n";
    }

    void run_tests()
    {
        test1();
        test2();
        test3();
    }

}
