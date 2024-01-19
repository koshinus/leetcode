#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <string>

#include "support_func.hpp"
/*
void printStats(const std::map<char, std::vector<int>>& stats)
{
    for (auto it = stats.begin(); it != stats.end(); it++)
    {
        std::cout << it->first << "->";
        support::print_vec(it->second);
    }
}

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

struct StatInfo
{
    int pos;
    int len;
};

int getPosition(const std::vector<int>& positions, int threshold)
{
    if (positions.empty())
        return -1;
    if (threshold == -1)
        return positions.back();
    for (int i = positions.size() - 1; i >= 0; i--)
    {
        if (positions[i] >= threshold)
            continue;
        return positions[i];
    }
    return -1;
}

StatInfo getLongestFrom(const std::map<char, std::vector<int>>& stats,
    const std::vector<StatInfo>& subseq_stat, char c, int from)
{
    auto stat_it = stats.find(c);
    if (stat_it == stats.end())
        return { -1,0 };
    auto& vals = stat_it->second;
    StatInfo stat_max{ -1,0 }, cur;
    for (int i = from; i < subseq_stat.size(); i++)
    {
        auto& stat_info = subseq_stat[i];
        cur = StatInfo{ -1, stat_info.len };
        if (cur.pos = getPosition(vals, stat_info.pos); cur.pos == -1)
            continue;
        else
            cur.len++;
        if (cur.len > stat_max.len)
            stat_max = cur;
    }
    return stat_max;
}

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
    int res = 0;
    auto stats = getStats(longer);
    std::vector<StatInfo> subseq_stat(shorter.size(), {-1,0});
    for (int i = shorter.size() - 1; i >= 0; i--)
    {
        subseq_stat[i] = getLongestFrom(stats, subseq_stat, shorter[i], i);
        //std::cout << "Stat info: " << subseq_stat[i].pos << "->" << subseq_stat[i].len << "\n";
        res = std::max(res, subseq_stat[i].len);
    }
    for (int i = 0; i < subseq_stat.size(); i++)
    {
        std::cout << "{" << subseq_stat[i].pos << "," << subseq_stat[i].len << "},";
    }
    std::cout << "\n";
    return res;
}

int longestCommonSubsequence(std::string text1, std::string text2)
{
    int t1_size = text1.size(), t2_size = text2.size();
    if (t1_size == 0 || t2_size == 0)
        return 0;
    bool t1_longer = t1_size > t2_size;
    return getLongest( t1_longer ? text2 : text1,
                        t1_longer ? text1 : text2 );
}
*/

bool isPrefix(const std::string& shorter, const std::string& longer)
{
    for (int i = 0; i < shorter.size(); i++)
    {
        if (shorter[i] != longer[i])
            return false;
    }
    return true;
}

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

int symbolFit(const std::map<char, std::vector<int>>& stats, char symbol, int req_pos)
{
    auto it = stats.find(symbol);
    if (it == stats.end())
        return -1;
    auto& vals = it->second;
    for (int elem : vals)
    {
        if (elem > req_pos)
            return elem;
    }
    return -1;
}

struct StrInfo
{
    //std::string s;
    int s_pos;
    int stat_pos;
};

std::vector<StrInfo> getFirstGeneration(const std::string& str,
    const std::map<char, std::vector<int>>& stats)
{
    std::vector<StrInfo> first_gen;
    first_gen.reserve(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (int stat_pos = symbolFit(stats, str[i], -1); stat_pos != -1)
        {
            //std::cout << "Stat pos is " << stat_pos << "\n";
            first_gen.emplace_back(StrInfo{
                //std::string{ str[i] }, 
                i, stat_pos });
        }
    }
    return first_gen;
}

std::vector<StrInfo> enchant(const std::vector<StrInfo>& prev_generation,
    const std::map<char, std::vector<int>>& stats,
    const std::string& test_str)
{
    std::vector<StrInfo> new_generation;
    new_generation.reserve(prev_generation.size());
    for (auto& elem : prev_generation)
    {
        for (int i = elem.s_pos; i < test_str.size(); i++)
        {
            if (int new_stat_pos = symbolFit(stats, test_str[i], elem.stat_pos); new_stat_pos != -1)
            {
                //std::string new_str = elem.s + test_str[i];
                std::cout
                    //<< new_str << "->" 
                    << "[" << i << "," << new_stat_pos << "]\n";
                new_generation.emplace_back(StrInfo{
                    //new_str,
                    i, new_stat_pos });
            }
        }
    }
    return new_generation;
}

int getLongest(const std::string& shorter, const std::string& longer)
{
    if (isPrefix(shorter, longer))
        return shorter.size();
    int res = 0, cur_val = 0;
    //std::cout << shorter << "->" << longer << std::endl;
    auto stats = getStats(longer);
    std::vector<StrInfo> generation = getFirstGeneration(shorter, stats);
    //std::cout << "First generation size is " << generation.size() << "\n";
    while (res < shorter.size() && !generation.empty())
    {
        res++;
        generation = enchant(generation, stats, shorter);
        //std::cout << "Generation size is " << generation.size() << "\n";
    }
    return res;
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
        std::cout << longestCommonSubsequence("mhunuzqrkzsnidwbun", "szulspmhwpazoxijwbq") << "\n";
    }

    void run_tests()
    {
        //test1();
        //test2();
        //test3();
        //test4();
        //test5();
        //test6();
        //test7();
        test8();
    }
}