#pragma once

#include <vector>
#include <list>

#include "support_func.hpp"
#include "intervals_structures.hpp"

bool does_intervals_intersects(const OneInterval& left, const OneInterval& right)
{
    if (left[0] == right[0] && left[1] == right[1])
    {
        return true;
    }
    const OneInterval* correct_left = &left;
    const OneInterval* correct_right = &right;
    if (right[0] <= left[0])
    {
        correct_left = &right;
        correct_right = &left;
    }
    return (*correct_left)[1] <= (*correct_right)[0];
}

bool have_intersections( const std::list<OneInterval>& list_to_check, const OneInterval& interval )
{
    for (auto& elem : list_to_check)
    {
        if (does_intervals_intersects(elem, interval))
        {
            return true;
        }
    }
    return false;
}

int how_many_to_remove(const Intervals& intervals, int idx)
{
    //int rem_counter = 0;
    std::list<OneInterval> list_to_check;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (i == idx)
        {
            continue;
        }
        auto& check_int = intervals[i];
        if (have_intersections(list_to_check, check_int))
        {
            //std::cout << list_to_check.size() << " intersected interval: [" << check_int[0] << "," << check_int[1] << "]\n";
                //<< "|" << rem_counter << "\n";
            //rem_counter++;
            //std::cout << "Rem counter is " << rem_counter << "\n";
            continue;
        }
        list_to_check.push_back(check_int);
    }
    return intervals.size() - list_to_check.size();
    //return rem_counter;
}

int eraseOverlapIntervals(Intervals& intervals)
{
    int min_to_remove = intervals.size();
    for (int i = 0; i < intervals.size(); i++)
    {
        min_to_remove = std::min(min_to_remove, how_many_to_remove(intervals, i));
    }
    return min_to_remove;
}

namespace non_overlap_intervals
{
    void run_tests()
    {
        Intervals intervals{ {1,2},{2,3},{3,4},{1,3} };
        std::cout << "Min erase intervals:" << eraseOverlapIntervals(intervals); // answer should be 1

        std::cout << "\n";

        Intervals intervals1{ {1,2},{1,2},{1,2} };
        std::cout << "Min erase intervals:" << eraseOverlapIntervals(intervals1); // answer should be 2

        std::cout << "\n";

        Intervals intervals2{ {1,2},{2,3} };
        std::cout << "Min erase intervals:" << eraseOverlapIntervals(intervals2); // answer should be 0
    }
}