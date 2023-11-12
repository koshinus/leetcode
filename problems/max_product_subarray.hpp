#pragma once

#include <vector>
#include <iostream>

int maxProduct(std::vector<int>& nums)
{
    int max_in_nums = nums[0], max_product = 1, cur_product = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur_val = nums[i];
        max_in_nums = std::max( max_in_nums, cur_val );
        cur_product = std::max( cur_val * cur_product, 1 );
        max_product = std::max( max_product, cur_product );
    }
    return ( max_product > 1 ) ? max_product : max_in_nums;
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
              << maxProduct(vec2) //WRONG: should be 3, not -1
        ;
}

}
