#pragma once

#include <vector>

#include "support_func.hpp"

int findNextMin(const std::vector<int>& nums, int idx, int threshold)
{
    // auto min_it = std::min_element(nums.begin() + i, nums.end());
    // if(min_it == nums.end())
    //     return -1;
    // return std::distance(nums.begin(), min_it);
    int idx_min = -1, min_el = nums[idx], cur_val;
    for (int i = idx; i < nums.size(); i++)
    {
        cur_val = nums[i];
        if (cur_val <= threshold)
            continue;
        if (cur_val < min_el)
        {
            idx_min = i;
            min_el = cur_val;
        }
    }
    std::cout << idx << "/" << threshold << "\n";
    return idx_min;
}

int lengthFromIdx(const std::vector<int>& nums, int i)
{
    int res = 0;
    do
    {
        res++;
        i = findNextMin(nums, i + 1, nums[i]);
    } while (i != -1);
    return res;
}

int lengthOfLIS(std::vector<int>& nums)
{
    int largest = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        largest = std::max(largest, lengthFromIdx(nums, i));
    }
    return largest;
}

namespace longest_subseq
{
    void test1()
    {
        std::vector<int> vec{10,9,2,5,3,7,101,18};
        std::cout << lengthOfLIS(vec);
    }

    void test2()
    {
        std::vector<int> vec{ 0,1,0,3,2,3 };
        std::cout << lengthOfLIS(vec);
    }
    
    void test3()
    {
        std::vector<int> vec{ 7,7,7,7,7,7,7 };
        std::cout << lengthOfLIS(vec);
    }

    void run_tests()
    {
        test1();
        //test2();
        //test3();
    }
}