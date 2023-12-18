#pragma once
#include <string>
#include <vector>
#include <iostream>

struct StrIndexes
{
    int start;
    int end;
};

std::string getSubstring(const std::string& s, int start, int end)
{
    if (s.empty())
        return "";
    std::cout << "Str size: " << s.size() << " " << start << " " << end << "\n";
    return std::string(s.c_str() + std::max(start, 0),
        s.c_str() + std::min(end + 1, static_cast<int>(s.size())));
}

StrIndexes getRepeatingSequenceIndexes_(const std::string& s, int i)
{
    char c = s[i];
    int s_size = s.size();
    if (s[i - 1] != c && s[i + 1] != c)
    {
        return { i,i };
    }
    int left = i - 1, right = i + 1;
    while (left - 1 > -1 && s[left - 1] == c)
        left--;
    while (right + 1 < s_size && s[right + 1] == c)
        right++;
    return { left, right };
}

StrIndexes getIndexesForEdges(const std::string& s, int i)
{
    int left = i - 1, right = i + 1;
    if (s[left] == s[right])
        return { left, right };
    if (s[left] == s[i])
        return { left, i };
    if (s[right] == s[i])
        return { i, right };
    return { i, i };
}

StrIndexes getIndexesForCurrent_(const std::string& s, int i)
{
    int s_size = s.size();
    if ((i - 1) == 0 || (i + 1) == s_size - 1)
    {
        return getIndexesForEdges(s, i);
    }
    auto [left, right] = getRepeatingSequenceIndexes_(s, i);
    if (left > 0 && right < s_size && s[left - 1] != s[right + 1])
    {
        return { left, right };
    }
    while (left - 1 > -1 && right + 1 < s_size && s[left - 1] == s[right + 1])
    {
        left--;
        right++;
    }
    return { left, right };
}

std::string longestPalindrome(std::string s)
{
    int s_size = s.size();
    if (s_size == 1)
        return s;
    if (s_size == 2)
    {
        if (s[0] == s[1])
            return s;
        else
            return std::string( 1, s[0] );
    }
    StrIndexes largest = {0, 0}, current;
    for (int i = 1; i < s.size() - 1; i++)
    {
        current = getIndexesForCurrent_(s, i);
        if (current.start == 0 && current.end == s_size - 1)
            return s;
        if ((current.end - current.start) > (largest.end - largest.start))
            largest = current;
        /*
        std::cout << "Left is " << current.start
                  << ", right is " << current.end
                  << ", substring is " << getSubstring(s, current.start, current.end) << "\n";
                  //*/
    }
    return getSubstring(s, largest.start, largest.end);
}

namespace longest_pal
{

    void run_tests()
    {
        std::cout << longestPalindrome("babad") << '\n' // should be bab or aba
            << longestPalindrome("cbbd") << '\n' // should be bb
            << longestPalindrome("a") << '\n' // should be a
            << longestPalindrome("ac") << '\n' // should be a
            << longestPalindrome("cadabbuuuuuubbai") << '\n' // should be abbuuuuuubba
            << longestPalindrome("dgshjagdgpolkyyyyyyyyyykl") << '\n' // should be lkyyyyyyyyyykl
            << longestPalindrome("cadabbuuuuuubbo") << '\n' // should be bbuuuuuubb
            << longestPalindrome("aaaa") << '\n'; // should be aaaa
    }

}