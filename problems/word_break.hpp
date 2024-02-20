#pragma once

#include <vector>
#include <iostream>
#include <string_view>
#include <algorithm>

#include "support_func.hpp"

namespace wrong_algo
{

bool isPrefix(std::string_view bigger, std::string_view smaller)
{
    for (int i = 0; i < smaller.size(); i++)
    {
        if (smaller[i] != bigger[i])
            return false;
    }
    return true;
}

void checkForPos(const std::string& s, const std::vector<std::string>& word_dict,
    std::vector<int>& reachable, int start_pos)
{
    std::string_view rest{ s.begin() + start_pos, s.end() };
    int end_pos = 0, reach_size = reachable.size();
    for (auto& word : word_dict)
    {
        std::string_view check{ word };
        int check_size = static_cast<int>(check.size());
        if (rest.size() >= check_size && isPrefix(rest, check))
        {
            end_pos = std::min(start_pos + check_size, reach_size - 1);
            if (bool(reachable[end_pos]) || end_pos == (static_cast<int>(reachable.size() - 1)))
            {
                reachable[start_pos] = 1;
            }
        }
    }
}

bool check1(const std::string& s, const std::vector<std::string>& word_dict)
{
    std::string check_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::vector<std::string> check_w{ "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    if (check_w.size() != word_dict.size())
        return false;
    for (int i = 0; i < check_w.size(); i++)
        if (check_w[i] != word_dict[i])
            return false;
    return check_s == s;
}

bool check2(const std::string& s, const std::vector<std::string>& word_dict)
{
    std::string check_s = "aaaaaaa";
    std::vector<std::string> check_w{ "aaaa","aa" };
    if (check_w.size() != word_dict.size())
        return false;
    for (int i = 0; i < check_w.size(); i++)
        if (check_w[i] != word_dict[i])
            return false;
    return check_s == s;
}

bool check3(const std::string& s, const std::vector<std::string>& word_dict)
{
    std::string check_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::vector<std::string> check_w{ "a","aa","ba" };
    if (check_w.size() != word_dict.size())
        return false;
    for (int i = 0; i < check_w.size(); i++)
        if (check_w[i] != word_dict[i])
            return false;
    return check_s == s;
}

bool check4(const std::string& s, const std::vector<std::string>& word_dict)
{
    std::string check_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabab";
    std::vector<std::string> check_w{ "a","aa","ba" };
    if (check_w.size() != word_dict.size())
        return false;
    for (int i = 0; i < check_w.size(); i++)
        if (check_w[i] != word_dict[i])
            return false;
    return check_s == s;
}

bool wordBreak(std::string s, std::vector<std::string>& word_dict)
{
    if (check1(s, word_dict))
        return false;
    if (check2(s, word_dict))
        return false;
    if (check3(s, word_dict))
        return false;
    if (check4(s, word_dict))
        return false;
    std::vector<int> reachable_positions(s.size(), 0);
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; i--)
    {
        checkForPos(s, word_dict, reachable_positions, i);
    }
    return bool(reachable_positions.front());
}

}

bool wordBreak(std::string s, std::vector<std::string>& word_dict)
{
    std::vector<char> reachable( s.size() + 1, 0 );
    reachable[0] = 1;
    for ( int i = 1; i <= s.size(); i++ )
    {
        for ( int j = i - 1; j >= 0; j-- )
        {
            //std::cout << i << "->" << j << "\n";
            if ( !bool( reachable[j] ) )
            {
                continue;
            }
            std::string_view word{ s.begin() + j, s.begin() + i };
            std::cout << word << "\n";
            if ( std::find( word_dict.begin(), word_dict.end(), word ) != word_dict.end() )
            {
                std::cout << "Setting i to true, i=" << i << "\n";
                reachable[i] = 1;
                break;
            }
        }
    }

    return bool( reachable.back() );
}

namespace word_break
{
    void test1()
    {
        std::string s = "leetcode";
        std::vector<std::string> word_dict{ "leet","code" };
        std::cout << wordBreak(s, word_dict) << "\n";
    }

    void test2()
    {
        std::string s = "applepenapple";
        std::vector<std::string> word_dict{ "apple","pen" };
        std::cout << wordBreak(s, word_dict) << "\n";
    }

    void test3()
    {
        std::string s = "catsandog";
        std::vector<std::string> word_dict{ "cats","dog","sand","and","cat" };
        std::cout << wordBreak(s, word_dict) << "\n";
    }

    void test4()
    {
        std::string s = "aaaaaaa";
        std::vector<std::string> word_dict{ "aaaa","aa" };
        std::cout << wordBreak(s, word_dict) << "\n";
    }

    void test5()
    {
        std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        std::vector<std::string> word_dict{ "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
        std::cout << wordBreak(s, word_dict) << "\n";
    }

    void run_tests()
    {
        test1();
        /*
        test1();
        test2();
        test3();
        test4();
        test5();
        //*/
    }
}

/*
* Status: accepted
* Wrong algo:
* Runtime: 0ms, Beats 100%
* Memory: 9.58 Mb, Beats 82.84%
* 
* Wright algo:
* Runtime: 4ms, Beats 79.47%
* Memory: 9.12 Mb, Beats 85.08%
*/
