#pragma once

#include <vector>

#include "support_func.hpp"
#include "intervals_structures.hpp"

int eraseOverlapIntervals(Intervals& intervals)
{

}

namespace non_overlap_intervals
{
    void run_tests()
    {
        Intervals intervals{ {1,2},{2,3},{3,4},{1,3} };
        std::cout << eraseOverlapIntervals(intervals); // answer should be 1

        Intervals intervals1{ {1,2},{1,2},{1,2} };
        std::cout << eraseOverlapIntervals(intervals1); // answer should be 2
    }
}