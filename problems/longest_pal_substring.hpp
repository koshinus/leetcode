#pragma once
#include <string>
#include <vector>
#include <iostream>

struct StrIndexes
{
    int start;
    int end;
};

StrIndexes getPalindromicIdxs(const std::string& s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return { left + 1, right - 1 };
}

std::string longestPalindrome(std::string s)
{
    int s_size = s.size();
    if (s_size <= 1)
        return s;

    StrIndexes largest = { 0, 0 }, current;

    for (int i = 0; i < s_size - 1; i++)
    {
        current = getPalindromicIdxs(s, i, i);
        if ((largest.end - largest.start) < (current.end - current.start))
            largest = current;

        current = getPalindromicIdxs(s, i, i + 1);
        if ((largest.end - largest.start) < (current.end - current.start))
            largest = current;
    }

    return s.substr(largest.start, largest.end - largest.start + 1);
}

namespace longest_pal
{

    void run_tests()
    {
        std::cout 
            << longestPalindrome("babad") << '\n' // should be bab or aba
            << longestPalindrome("cbbd") << '\n' // should be bb
            << longestPalindrome("a") << '\n' // should be a
            << longestPalindrome("ac") << '\n' // should be a
            << longestPalindrome("cadabbuuuuuubbai") << '\n' // should be abbuuuuuubba
            << longestPalindrome("dgshjagdgpolkyyyyyyyyyykl") << '\n' // should be lkyyyyyyyyyykl
            << longestPalindrome("cadabbuuuuuubbo") << '\n' // should be bbuuuuuubb
            << longestPalindrome("aaaa") << '\n'
            << longestPalindrome("abbcccbbbcaaccbababcbcabca") << '\n'; // should be bbcccbb 
    }

}

//TODO: wright independently after some time

/*
* Status: accepted
* Runtime: 13ms, Beats 71.52%
* Memory: 7.26 Mb, Beats 85.54%
*/
