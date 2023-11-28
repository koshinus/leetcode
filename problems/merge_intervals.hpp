#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

#include "support_func.hpp"
#include "intervals_structures.hpp"

int merge_interval_to_existed(Intervals& intervals, const OneInterval& other)
{
    if (intervals.empty())
    {
        intervals.push_back(other);
        return 0; // last index
    }
    int last = intervals.size() - 1;
    auto& last_int = intervals[last];
    if (last_int[1] >= other[0])
    {
        last_int[1] = std::max(other[1], last_int[1]);
        return last;
    }
    intervals.push_back(other);
    return intervals.size() - 1;
}

Intervals merge(Intervals& intervals)
{
    if (intervals.empty())
    {
        return {};
    }
    std::sort(intervals.begin(), intervals.end(),
        [](const OneInterval& left, const OneInterval& right)
        {
            return left[0] < right[0];
        });
    Intervals res;
    res.reserve(intervals.size());
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        merge_interval_to_existed(res, intervals[i]);
    }
    return res;
}


namespace merge_intervals
{
    void run_tests()
    {
        std::vector< std::vector<int>> intervals{ {1,3} ,{2,6},{8,10},{15,18} };
        auto res = merge(intervals);
        std::cout << "[";
        for (auto& vec : res)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";


        std::vector< std::vector<int>> intervals1{ {1,4} ,{4,5} };
        auto res1 = merge(intervals1);
        std::cout << "[";
        for (auto& vec : res1)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        std::vector< std::vector<int>> intervals2{ {1,4} ,{0,4} };
        auto res2 = merge(intervals2);
        std::cout << "[";
        for (auto& vec : res2)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        std::vector< std::vector<int>> intervals3{ {1,4} ,{2,3} };
        auto res3 = merge(intervals3);
        std::cout << "[";
        for (auto& vec : res3)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";
    }
}

/*
* Status: accepted
* Runtime: 22ms, Beats 97.87%
* Memory: 18.92 Mb, Beats 97.68%
*/
