#pragma once

#include <map>
#include <vector>

#include "support_func.hpp"

int getLongestFrom(const std::vector<int>& nums, const std::vector<int>& paths, int from)
{
    int res = 0, threshold = nums[from];
    for (int i = from; i < nums.size(); i++)
    {
        if (nums[i] <= threshold)
            continue;
        res = std::max(paths[i], res);
    }
    return res;
}

int lengthOfLIS(std::vector<int>& nums)
{
    std::vector<int> longest_paths( nums.size(), 0 );
    int res = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        longest_paths[i] = 1 + getLongestFrom(nums, longest_paths, i);
        res = std::max(res, longest_paths[i]);
    }
    //support::print_vec(longest_paths);
    return res;
}

namespace longest_subseq
{
    void test1()
    {
        std::vector<int> vec{10,9,2,5,3,7,101,18};
        std::cout << lengthOfLIS(vec) << "\n";
        //std::cout << lengthFromIdx(vec, 0);
    }

    void test2()
    {
        std::vector<int> vec{ 0,1,0,3,2,3 };
        std::cout << lengthOfLIS(vec) << "\n";
    }
    
    void test3()
    {
        std::vector<int> vec{ 7,7,7,7,7,7,7 };
        std::cout << lengthOfLIS(vec) << "\n";
    }

    void test4()
    {
        std::vector<int> vec{ 0,3,4,5,6,7,8,1,2 };
        std::cout << lengthOfLIS(vec) << "\n";
    }

    void test5()
    {
        std::vector<int> vec{ 0,3,4,5,6,7,8,1,2,3,4,5,6,7,8 };
        std::cout << lengthOfLIS(vec) << "\n";
    }

    void test6()
    {
        std::vector<int> vec{ 1,3,6,7,9,4,10,5,6 };
        std::cout << lengthOfLIS(vec) << "\n";
    }

    void run_tests()
    {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}

/*
* Status: accepted
* Runtime: 131ms, Beats 64.63%
* Memory: 10.75 Mb, Beats 77.94%
*/
