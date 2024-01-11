#pragma once

#include <map>
#include <vector>

#include "support_func.hpp"

int findNextMin(const std::vector<int>& nums, int idx, int threshold)
{
    if (idx >= nums.size())
        return -1;
    //std::cout << "Index is " << idx << " start val is " << nums[idx] << " threshold is " << threshold << "\n";
    int idx_min = -1,//idx,
        min_el = INT_MAX,//nums[idx],
        cur_val;
    for (int i = idx; i < nums.size(); i++)
    {
        cur_val = nums[i];
        if (cur_val <= threshold)
            continue;
        //std::cout << min_el << "/" << cur_val << "\n";
        if (cur_val < min_el)
        {
            idx_min = i;
            min_el = cur_val;
        }
    }
    //std::cout << idx_min << "->" << min_el << "\n";
    return idx_min;
}

int lengthFromIdx1(const std::vector<int>& nums, std::map<int, int>& min_idxs, int i)
{
    int res = 0;
    do
    {
        res++;
        auto it = min_idxs.find( i );
        if (it != min_idxs.end())
        {
            i = it->second;
            continue;
        }
        min_idxs[i] = findNextMin(nums, i + 1, nums[i]);
        i = min_idxs[i];
        //std::cout << "Res is " << res << " i is " << i << "\n";
    } while (i != -1);
    return res;
}

int lengthFromIdxOpt(const std::vector<int>& nums, std::vector<int>& min_idxs, int i)
{
    int res = 0;
    do
    {
        res++;
        if (min_idxs[i] != -1)
        {
            i = min_idxs[i];
            continue;
        }
        min_idxs[i] = findNextMin(nums, i + 1, nums[i]);
        i = min_idxs[i];
        //std::cout << "Res is " << res << " i is " << i << "\n";
    } while (i != -1);
    return res;
}

int lengthFromIdx(const std::vector<int>& nums, int i)
{
    int res = 0;
    do
    {
        res++;
        i = findNextMin(nums, i + 1, nums[i]);
        //std::cout << "Res is " << res << " i is " << i << "\n";
    } while (i != -1);
    return res;
}

int lengthOfLIS(std::vector<int>& nums)
{
    //std::map<int, int> min_idxs;
    std::vector<int> min_idxs(nums.size(), -1);
    int largest = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        //largest = std::max(largest, lengthFromIdx(nums, min_idxs, i));
        largest = std::max(largest, lengthFromIdx(nums, i));
    }
    return largest;
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