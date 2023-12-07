#pragma once
#include <string>
#include <vector>
#include <iostream>

struct StrIndexes
{
    int start;
    int end;
};

bool checkIfPalOnSides(std::string s, int i)
{
    if (i == 0 || i == s.size() - 1)
        return false;

}

StrIndexes getLargestSeq(const std::vector<StrIndexes>& idxs)
{
    StrIndexes largest{ 0,0 };
    for (auto& idx : idxs)
    {
        if ((idx.end - idx.start) > (largest.end - largest.start))
            largest = idx;
    }
    return largest;
}

StrIndexes getIndexesForCurrent(const std::string& s, int i)
{
    int s_size = s.size();
    if (i == 0 || i == s_size - 1)
        return { 0,0 };
    int left = i - 1, right = i + 1;
    while ( true )
    {
        //&& (left > -1) && (right < s_size)
        if ( !((left - 1 > -1) && (right + 1 < s_size)) )
        {
            break;
        }
        if (s[left] == s[right])
        {
            left--;
            right++;
            continue;
        }
        if (s[left] == s[left - 1])
            left--;
        if (s[right] == s[right + 1])
            left++;
    }
    if (left == i - 1)
    {
        if (s[left] == s[i])
            return  { left, i };
        if (s[right] == s[i])
            return  { i, right };
    }
    return { left, right };
}

std::string longestPalindrome(std::string s)
{
    //std::vector<StrIndexes> idxs;
    StrIndexes largest = {0, 0}, current;
    for (int i = 0; i < s.size(); i++)
    {
        current = getIndexesForCurrent(s, i);
        if (current.start == 0 && current.end == s.size() - 1)
            return s;
        if ((current.end - current.start) > (largest.end - largest.start))
            largest = current;
    }
    //auto largest = getLargestSeq(idxs);
    return std::string( s.c_str() + largest.start, s.c_str() + largest.end );
}

namespace longest_pal
{

    void run_tests()
    {
        std::cout << longestPalindrome("babad") << '\n' // should be bab or aba
                  << longestPalindrome("cbbd") << '\n' // should be bb
                  << longestPalindrome("a") << '\n' // should be a
                  << longestPalindrome("cadabbuuuuuubbai") << '\n' // should be abbuuuuuubba
                  << longestPalindrome("dgshjagdgpolkyyyyyyyyyykl") << '\n' // should be lkyyyyyyyyyykl
                  << longestPalindrome("cadabbuuuuuubbo") << '\n'; // should be bbuuuuuubb
    }

}