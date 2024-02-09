#pragma once

#include <vector>
#include <iostream>

#include "support_func.hpp"

int combinationSum4(std::vector<int>& nums, int target)
{
    if (target == 0)
        return 0;
    std::vector<size_t> targets(target + 1, 0);
    bool target_in_nums = false;
    for (int num : nums)
    {
        if (num < target)
            targets[num] = 1;
        if (num == target)
            target_in_nums = true;
    }
    for (int i = 1; i <= target; i++)
    {
        for (int num : nums)
        {
            if (num <= i)
                targets[i] += targets[i - num];
        }
    }
    //support::print_vec(targets);
    return target_in_nums ? targets.back() + 1 : targets.back();
}

namespace combination_sum
{

    void test1()
    {
        std::vector<int> vec{ 1,2,3 };
        int target = 4;
        std::cout << combinationSum4(vec, target) << "\n";
    }

    void test2()
    {
        std::vector<int> vec{ 9 };
        int target = 3;
        std::cout << combinationSum4(vec, target) << "\n";
    }

    void test3()
    {
        std::vector<int> vec{ 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
        int target = 10;
        std::cout << combinationSum4(vec, target) << "\n";
    }

    void test4()
    {
        std::vector<int> vec{ 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,
            200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,
            410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,
            620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,
            830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111 };
        int target = 999;
        std::cout << combinationSum4(vec, target) << "\n";
    }

    void run_tests()
    {
        test1();
        test2();
        test3();
        test4();
    }
}

/*
* Status: accepted
* Runtime: 3ms, Beats 49.15%
* Memory: 7.88 Mb, Beats 22.47%
*/
