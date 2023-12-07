#pragma once

#include <vector>
#include <iostream>

// TODO: analyze and understand more precisely
int maxProduct(std::vector<int>& nums)
{
    int max_global = nums[0], max_cur, min_cur, max_pre = nums[0], min_pre = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int cur_val = nums[i];
        max_cur = std::max( std::max(max_pre * cur_val, min_pre*cur_val), cur_val );
        min_cur = std::min( std::min(max_pre * cur_val, min_pre*cur_val), cur_val );
        max_global = std::max( max_global, max_cur );
        max_pre = max_cur;
        min_pre = min_cur;
    }
    return max_global;
}

namespace max_product
{

void run_tests()
{
    std::vector<int> vec{2,3,-2,4};
    std::vector<int> vec1{-2,0,-1};
    std::vector<int> vec2{-3,-1,-1};
    std::cout << maxProduct(vec) << "\n"
              << maxProduct(vec1) << "\n"
              << maxProduct(vec2);
}

}

/*
* Status: accepted
* Runtime: 7ms, Beats 36.26%
* Memory: 14.19 Mb, Beats 39.51%
*/
