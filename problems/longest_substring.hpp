#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <string>

#include "support_func.hpp"

bool isPrefix(const std::string& shorter, const std::string& longer)
{
    for (int i = 0; i < shorter.size(); i++)
    {
        if (shorter[i] != longer[i])
            return false;
    }
    return true;
}

int getLongest(const std::string& shorter, const std::string& longer)
{
    if (isPrefix(shorter, longer))
        return shorter.size();
    std::vector<std::vector<int>> strs_stat(shorter.size() + 1, std::vector<int>(longer.size() + 1, 0));

    for (int i = 0; i < shorter.size(); i++)
    {
        for (int j = 0; j < longer.size(); j++)
        {
            strs_stat[i + 1][j + 1] = shorter[i] == longer[j] ?
                strs_stat[i][j] + 1 :
                std::max(strs_stat[i + 1][j], strs_stat[i][j + 1]);
        }
    }
    return strs_stat.back().back();
}

int longestCommonSubsequence(std::string text1, std::string text2)
{
    int t1_size = text1.size(), t2_size = text2.size();
    if (t1_size == 0 || t2_size == 0)
        return 0;
    bool t1_longer = t1_size > t2_size;
    return getLongest(t1_longer ? text2 : text1,
        t1_longer ? text1 : text2);
}

namespace longest_substr
{
    void test1()
    {
        std::cout << longestCommonSubsequence("dfffksjah", "sss") << "\n";
    }

    void test2()
    {
        std::cout << longestCommonSubsequence("d", "d") << "\n";
    }

    void test3()
    {
        std::cout << longestCommonSubsequence("h", "sss") << "\n";
    }

    void test4()
    {
        std::cout << longestCommonSubsequence("abcde", "arce") << "\n";
    }

    void test5()
    {
        std::cout << longestCommonSubsequence("abc", "abc") << "\n";
    }

    void test6()
    {
        std::cout << longestCommonSubsequence("def", "abc") << "\n";
    }

    void test7()
    {
        std::cout << longestCommonSubsequence("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << "\n";
    }

    void test8()
    {
        //mhziwb->[15,17]
        // mhunuzqrkzsnidwbun -> mh unuzqrk z sn i d wb un
        // szulspmhwpazoxijwbq -> szulsp mh wpa z ox i j wb q
        std::cout << longestCommonSubsequence("mhunuzqrkzsnidwbun", "szulspmhwpazoxijwbq") << "\n";
    }

    void run_tests()
    {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
    }
}

//TODO: wright independently after some time
//TODO: wright optimized solution

/*
* Status: accepted
* Runtime: 20ms, Beats 90.94%
* Memory: 19.72 Mb, Beats 70.59%
*/
