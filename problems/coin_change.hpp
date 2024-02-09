#pragma once

#include <vector>
#include <iostream>
#include <map>

#include "support_func.hpp"

int coinChange(std::vector<int>& coins, int amount)
{
    if (amount == 0)
        return 0;
    int default_val = amount + 1;
    std::vector<int> dp(amount + 1, default_val);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
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

//TODO: wright independently after some time

/*
* Status: accepted
* Runtime: 22ms, Beats 94.18%
* Memory: 15.94 Mb, Beats 51.05%
*/
