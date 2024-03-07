#pragma once

#include <vector>

#include "support_func.hpp"

namespace wrong_algo
{

int rob(std::vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.front();
    if (nums.size() == 2)
        return std::max(nums[0], nums[1]);
    if (nums.size() == 3)
        return std::max(std::max(nums[0], nums[1]), nums[2]);
    if (nums.size() == 4)
        return std::max(nums[0] + nums[2], nums[1] + nums[3]);
    std::vector<int> amounts(nums.size(), 0);
    amounts[0] = nums[0];
    amounts[1] = nums[1];
    amounts[2] = nums[0] + nums[2];
    bool with_first_house = (amounts[0] + nums[2]) > amounts[1];
    //std::cout << "with_first_house=" << with_first_house << "\n";
    for (int i = 3; i < nums.size(); i++)
    {
        //        if (i == nums.size() - 1)
        //        {
        //            amounts[i] = std::max(amounts[i - 2], amounts[i - 3]) + (with_first_house ? 0 : nums[i]);
        //            continue;
        //        }
        amounts[i] = std::max(amounts[i - 2], amounts[i - 3]) + nums[i];
    }
    if (with_first_house)
        amounts.back() = amounts.back() - nums[0];
    support::print_vec(amounts);
    return std::max(std::max(amounts[amounts.size() - 2], amounts.back()), amounts[amounts.size() - 3]);
    //return std::max(amounts[amounts.size() - 2], amounts.back());
}

}

int rob(std::vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.front();
    if (nums.size() == 2)
        return std::max(nums[0], nums[1]);
    nums.push_back( nums.front() );
    std::vector<int> amounts(nums.size(), 0);
    amounts[0] = nums[0];
    amounts[1] = nums[1];
    amounts[2] = nums[0] + nums[2];
    bool with_first_house = (amounts[0] + nums[2]) > amounts[1];
    std::cout << "with_first_house=" << with_first_house << "\n";
    for (int i = 3; i < nums.size(); i++)
    {
        amounts[i] = std::max(amounts[i - 2], amounts[i - 3]) + nums[i];
    }
    support::print_vec(amounts);
    return std::max(amounts[amounts.size() - 2], amounts.back());
}

namespace house_robber2
{
    void test1()
    {
        std::vector<int> vec{ 2,3,2 };
        std::cout << rob( vec ) << ", answer should be 3" << "\n";
    }

    void test2()
    {
        std::vector<int> vec{ 1,2,3,1 };
        std::cout << rob(vec) << ", answer should be 4" << "\n";
    }

    void test3()
    {
        std::vector<int> vec{ 1,2,3 };
        std::cout << rob(vec) << ", answer should be 3" << "\n";
    }

    void test4()
    {
        std::vector<int> vec{ 200,3,140,20,10 };
        std::cout << rob(vec) << ", answer should be 340" << "\n";
    }

    void test5()
    {
        std::vector<int> vec{ 1,2,1,1 };
        std::cout << rob(vec) << ", answer should be 3" << "\n";
    }

    void test6()
    {
        std::vector<int> vec{ 2,7,9,3,1 };
        std::cout << rob(vec) << ", answer should be 11" << "\n";
    }

    void test7()
    {
        std::vector<int> vec{ 1,1,1,2 };
        std::cout << rob(vec) << ", answer should be 3" << "\n";
    }

    void test8()
    {
        std::vector<int> vec{ 6,6,4,8,4,3,3,10 };
        std::cout << rob(vec) << ", answer should be 27" << "\n";
    }

    void run_tests()
    {
        ///*
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        //*/
    }
}