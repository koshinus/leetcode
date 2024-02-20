#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "support_func.hpp"

namespace wrong_algo
{

int countForTwoSymbols(char first, char second)
{
    int num = (first - '0') * 10 + (second - '0');
    if (num == 0)
        return -1;
    if (num < 10 || (num > 20 && num % 10 == 0))
        return 0;
    if (num == 10 || num == 20 || num > 26)
        return 1;
    return 2;
}

void countNextPos_(std::vector<int>& vars, const std::string& s, int cur_pos)
{
    int s_size = s.size();
    if (cur_pos >= s_size)
        return;
    int res_for_two;
    if (cur_pos == 0)
    {
        vars[cur_pos] = 1;
        countNextPos_(vars, s, cur_pos + 1);
        return;
    }
    res_for_two = countForTwoSymbols(s[cur_pos - 1], s[cur_pos]);
    switch(res_for_two)
    {
    case 0:
    {
        //if (vars[cur_pos - 1] == 0)
        //    return;
        vars[cur_pos] = std::max( vars[cur_pos - 1] - 1, 0 );
        countNextPos_(vars, s, cur_pos + 1);
        return;
    }
    case 1:
    {
        vars[cur_pos] = vars[cur_pos - 1];
        countNextPos_(vars, s, cur_pos + 1);
        return;
    }
    case 2:
    {
        vars[cur_pos] = vars[cur_pos - 1] + 1;
        countNextPos_(vars, s, cur_pos + 1);
        return;
    }
    default: break;
    }
}

void countNextPos(std::vector<int>& vars, const std::string& s, int cur_pos)
{
    int s_size = s.size();
    if (cur_pos >= s_size)
        return;
    if (cur_pos == 0)
    {
        vars[cur_pos] = 1;
        countNextPos(vars, s, cur_pos + 1);
        return;
    }
    int res_for_two = countForTwoSymbols(s[cur_pos - 1], s[cur_pos]);
    switch (res_for_two)
    {
    case 0:
    {
        vars[cur_pos] = std::max(vars[cur_pos - 1] - 1, 0);
        countNextPos(vars, s, cur_pos + 1);
        return;
    }
    case 1:
    {
        vars[cur_pos] = vars[cur_pos - 1];
        countNextPos(vars, s, cur_pos + 1);
        return;
    }
    case 2:
    {
        vars[cur_pos] = vars[cur_pos - 1] + 1;
        countNextPos(vars, s, cur_pos + 1);
        countNextPos(vars, s, cur_pos + 2);
        return;
    }
    case -1:
    default:
        return;
    }
}

void countForNextPos(std::vector<int>& vars, const std::string& s, int start_idx)
{
    int res_for_two;
    int last_idx = s.size() - 1;
    for (int i = start_idx; i < s.size(); i+=2)
    {
        res_for_two = countForTwoSymbols(s[i - 1], s[i]);
        if (res_for_two == -1)
            return;
        if (res_for_two == 0)
            vars[i] = std::max(vars[i - 1] - 1, 0);
        if (res_for_two == 1)
            vars[i] = vars[i - 1];
        if (res_for_two == 2)
            vars[i] = vars[i - 1] + 1;
        /*
        if (res_for_two == 2)
        {
            if (i == last_idx && s.size() > 3)
                vars[i] = vars[i - 1] + 2;
            else
                vars[i] = vars[i - 1] + 1;
        }*/
    }
}

int numDecodings(std::string s)
{
    if (s.front() == '0')
        return 0;
    if (s.size() == 1)
        return 1;
    std::vector<int> variants_at_pos(s.size(), 0);
    variants_at_pos[0] = 1;
    //countNextPos(variants_at_pos, s, 0);
    countForNextPos(variants_at_pos, s, 1);
    countForNextPos(variants_at_pos, s, 2);
    support::print_vec(variants_at_pos);
    return variants_at_pos.back();
}

}

int numDecodings(std::string s)
{
    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    int way1, way2, last_val;
    for (int i = 2; i <= s.size(); i++)
    {
        way1 = s[i - 1] == '0' ? 0 : dp[i - 1];
        last_val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (last_val == 0)
            return 0;
        way2 = (last_val > 0 && last_val <= 26 && s[i - 2] != '0') ? dp[i - 2] : 0;
        dp[i] = way1 + way2;
    }
    support::print_vec(dp);
    return dp.back();
}

namespace decode_ways
{
    void test1()
    {
        std::cout << numDecodings("12") << "\n";
    }

    void test2()
    {
        std::cout << numDecodings("226") << "\n";
    }

    void test3()
    {
        std::cout << numDecodings("06") << "\n";
    }

    void test4()
    {
        std::cout << numDecodings("61008") << "\n";
    }

    void test5()
    {
        std::cout << numDecodings("27") << "\n";
    }

    void test6()
    {
        std::cout << numDecodings("10") << "\n";
    }

    void test7()
    {
        std::cout << numDecodings("2101") << "\n";
    }

    void test8()
    {
        std::cout << numDecodings("1201234") << "\n";
    }

    void test9()
    {
        std::cout << numDecodings("120123") << "\n";
    }

    void test10()
    {
        std::cout << numDecodings("1201") << "\n";
    }

    void test11()
    {
        std::cout << numDecodings("1123") << "\n";
    }

    void test12()
    {
        std::cout << numDecodings("123123") << "\n";
    }

	void run_tests()
	{
        ///*
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        test9();
        test10();
        //*/
        test11();
        test12();
	}
}

/*
* Status: accepted
* Runtime: 4ms, Beats 22.07%
* Memory: 7.53 Mb, Beats 26.47%
*/
