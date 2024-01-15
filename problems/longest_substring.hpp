#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <string>

#include "support_func.hpp"


std::map<char, std::vector<int>> getStats(const std::string& text)
{
    std::map<char, std::vector<int>> stat;
    for (int i = 0; i < text.size(); i++)
    {
        char c = text[i];
        auto c_it = stat.find(c);
        if (c_it != stat.end())
        {
            c_it->second.push_back(i);
            continue;
        }
        stat[c] = std::vector<int>{ i };
    }
    return stat;
}

std::string serial(const std::vector<int>& vec)
{
    std::string res = "[";
    for (int el : vec)
    {
        res += std::to_string(el) + ",";
    }
    res += "]";
    return res;
}

void printStats(const std::map<char, std::vector<int>>& stats)
{
    for (auto it = stats.begin(); it != stats.end(); it++)
    {
        std::cout << it->first << "->" << serial(it->second) << "\n";
    }
}

int getLongest(const std::string& shorter, const std::string& longer)
{
    int res = 0;
    //std::cout << shorter << "->" << longer << std::endl;
    auto stats = getStats(longer);
    //printStats(stats);
    for (int i = 0; i < shorter.size(); i++)
    {

    }
    return res;
}

int longestCommonSubsequence(std::string text1, std::string text2)
{
    int t1_size = text1.size(), t2_size = text2.size();
    if (t1_size == 0 || t2_size == 0)
        return 0;
    if (t1_size == 1 && t2_size == 1)
        return text1[0] == text2[0] ? 1 : 0;
    bool t1_longer = t1_size > t2_size;
    return getLongest(t1_longer ? text2 : text1,
        t1_longer ? text1 : text2);
}