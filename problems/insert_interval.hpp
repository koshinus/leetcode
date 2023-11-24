#pragma once

#include <vector>

#include "support_func.hpp"

using OneInterval = std::vector<int>;
using Intervals = std::vector<OneInterval>;

bool value_is_in_interval( const OneInterval& interval, int val )
{
    return (interval[0] <= val) && (val <= interval[1]);
}

bool value_is_between_intervals(const OneInterval& interval1, const OneInterval& interval2, int val)
{
    return value_is_in_interval({ interval1[1], interval2[0] }, val );
}

enum class ValPositionState
{
    OUTSIDE,
    INSIDE_LEFT,
    INSIDE_RIGHT,
    BETWEEN
};

struct PositionInfo
{
    ValPositionState state;
    int index;
};

ValPositionState get_val_position_state( const OneInterval& left, const OneInterval& right, int val )
{
    if (val < left[0] || val > right[1])
        return ValPositionState::OUTSIDE;
    if (value_is_in_interval(left, val))
        return ValPositionState::INSIDE_LEFT;
    if (value_is_in_interval(right, val))
        return ValPositionState::INSIDE_RIGHT;
    return ValPositionState::BETWEEN;
}

PositionInfo get_value_position_info( const Intervals& intervals, int start_pos, int val)
{
    int last = intervals.size() - 1;
    ValPositionState state;
    if (intervals[start_pos][0] > val)
    {
        return { ValPositionState::BETWEEN, start_pos };
    }
    for (int i = start_pos; i < last; i++)
    {
        state = get_val_position_state(intervals[i], intervals[i+1], val);
        switch (state)
        {
        case ValPositionState::INSIDE_LEFT: return { state, i };
        case ValPositionState::INSIDE_RIGHT:
        case ValPositionState::BETWEEN: return { state, i + 1 };
        case ValPositionState::OUTSIDE:
        default: continue;
        }
    }
    if (value_is_in_interval(intervals[last], val))
        return { ValPositionState::INSIDE_RIGHT, last };
    else
        return { ValPositionState::OUTSIDE, last };
}

Intervals merge_result(Intervals&& intervals, const PositionInfo& left, const PositionInfo& right, const OneInterval& newInterval)
{
    int left_pos = left.index, right_pos = right.index;

    if (right.state == ValPositionState::OUTSIDE && right_pos == intervals.size() - 1)
    {
        auto& left_interval = intervals[left_pos];
        std::vector<int> interval_for_insert = { std::min(left_interval[0], newInterval[0]), newInterval[1] };
        auto it_begin = intervals.begin();
        intervals.insert(intervals.erase(it_begin + left_pos, intervals.end()), interval_for_insert);
        return std::move(intervals);
    }
    if ( ( left_pos == right_pos ) || 
        (
            (left_pos + 1) == right_pos &&
            (left.state == ValPositionState::BETWEEN ||
            right.state == ValPositionState::BETWEEN)
        ) )
    {
        intervals[left_pos][0] = std::min(newInterval[0], intervals[left_pos][0]);
        intervals[left_pos][1] = std::max(newInterval[1], intervals[left_pos][1]);
        return std::move(intervals);
    }
    auto& left_interval = intervals[left_pos];
    auto& right_interval = intervals[right_pos];
    std::vector<int> interval_for_insert = { std::min(left_interval[0], newInterval[0]),
                                             std::max(right_interval[1], newInterval[1]) };
    auto it_begin = intervals.begin();
    intervals.insert(intervals.erase(it_begin + left_pos, it_begin + (right_pos + 1)), interval_for_insert);
    return std::move(intervals);
}

Intervals merge_last_pos(Intervals&& intervals, OneInterval&& newInterval)
{
    int last_pos = intervals.size() - 1;

    int inserted_interval_left = newInterval[0];
    int inserted_interval_right = newInterval[1];
    int last_interval_left = intervals[last_pos][0];
    int last_interval_right = intervals[last_pos][1];

    if (last_interval_right < inserted_interval_left)
    {
        intervals.emplace_back(newInterval);
        return std::move(intervals);
    }
    if ((last_interval_left <= inserted_interval_left) && (inserted_interval_right <= last_interval_right))
    {
        return std::move(intervals);
    }
    intervals[last_pos][1] = inserted_interval_right;
    return std::move(intervals);
}

Intervals merge_interval(Intervals&& intervals, OneInterval&& newInterval, int left_interval_pos, int right_interval_pos)
{
    int inserted_interval_left = newInterval[0];
    int inserted_interval_right = newInterval[1];

    auto& left_interval = intervals[left_interval_pos];
    auto& right_interval = intervals[right_interval_pos];
    
    if ( right_interval_pos == left_interval_pos + 1 )
    {
        int left_end = left_interval[1];
        int right_start = right_interval[0];
        if ( ( inserted_interval_left > left_end ) &&
             ( inserted_interval_right < right_start ) )
        {
            intervals.insert( intervals.begin() + left_interval_pos, newInterval );
            return std::move( intervals );
        }
    }

    std::vector<int> interval_for_insert = { std::min( left_interval[ 0 ], inserted_interval_left ),
                                             std::max( right_interval[ 1 ], inserted_interval_right ) };
    auto it_begin = intervals.begin();
    intervals.insert( intervals.erase( it_begin + left_interval_pos, it_begin + ( right_interval_pos + 1 ) ), interval_for_insert );
    return std::move( intervals );
}

Intervals first_algo(Intervals& intervals, OneInterval& newInterval)
{
    int left_pos = 0, right_pos = intervals.size();
    int new_int_left = newInterval[0], new_int_right = newInterval[1];

    if (intervals.empty())
    {
        return { {new_int_left, new_int_right} };
    }
    if (new_int_right < intervals[0][0])
    {
        intervals.insert(intervals.begin(), std::move(newInterval));
        return std::move(intervals);
    }
    if (new_int_left > intervals[right_pos - 1][1])
    {
        intervals.emplace_back(std::move(newInterval));
        return std::move(intervals);
    }

    for (int i = 0; i < intervals.size(); i++)
    {
        std::cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]\n";
        if (value_is_in_interval(intervals[i], new_int_left))
        {
            std::cout << "1cur pos is " << i << "\n";
            left_pos = i;
            break;
        }
        if (i == 0)
        {
            continue;
        }
        if (value_is_between_intervals(intervals[i - 1], intervals[i], new_int_left))
        {
            std::cout << "2cur pos is " << i << "\n";
            left_pos = i;
            break;
        }
    }
    for (int i = left_pos; i < intervals.size(); i++)
    {
        std::cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]\n";
        if (value_is_in_interval(intervals[i], new_int_right))
        {
            std::cout << "3cur pos is " << i << "\n";
            right_pos = i;
            break;
        }
        if (i == 0)
        {
            continue;
        }
        if (value_is_between_intervals(intervals[i - 1], intervals[i], new_int_right))
        {
            std::cout << "4cur pos is " << i << "\n";
            right_pos = i;
            break;
        }
    }
    int pos_diff = right_pos - left_pos;
    std::cout << "left is " << left_pos << " right pos is " << right_pos << " pos diff is " << pos_diff << "\n";
    //return {};
    ///*
    //if ((pos_diff > 1) || (pos_diff == 1 && value_is_in_interval(intervals[right_pos], new_int_right)))
    if (pos_diff > 1)
    {
        return merge_interval(std::move(intervals), std::move(newInterval), left_pos, right_pos);
    }
    else
    {
        auto& interval = intervals[left_pos];
        interval[0] = std::min(interval[0], new_int_left);
        interval[1] = std::max(interval[1], new_int_right);
        return std::move(intervals);
    }
    //*/
}

Intervals second_algo(Intervals& intervals, OneInterval& newInterval)
{
    int left_pos = 0, right_pos = intervals.size();
    int new_int_left = newInterval[0], new_int_right = newInterval[1];

    if (intervals.empty())
    {
        return { {new_int_left, new_int_right} };
    }
    if (new_int_right < intervals[0][0])
    {
        intervals.insert(intervals.begin(), std::move(newInterval));
        return std::move(intervals);
    }
    if (new_int_left > intervals[right_pos - 1][1])
    {
        intervals.emplace_back(std::move(newInterval));
        return std::move(intervals);
    }
    auto left_pos_info = get_value_position_info(intervals, 0, new_int_left);
    std::cout << "Left interval pos " << left_pos_info.index << "\n";
    auto right_pos_info = get_value_position_info(intervals, left_pos_info.index, new_int_right);
    std::cout << "Right interval pos " << right_pos_info.index << " state is " << static_cast<int>(right_pos_info.state) << "\n";
    return merge_result(std::move( intervals ), left_pos_info, right_pos_info, newInterval);
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    return second_algo( intervals, newInterval );
}


namespace insert_interval
{

    void run_tests()
    {
        std::vector< std::vector<int>> intervals{ {1,3}, {6,9} };
        std::vector<int> new_interval{ 2,5 };
        auto res = insert( intervals, new_interval );
        std::cout << "[";
        for (auto& vec : res)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        ///*
        std::vector< std::vector<int>> intervals1{ {1,2},{3,5},{6,7},{8,10},{12,16} };
        std::vector<int> new_interval1{ 4,8 };
        auto res1 = insert(intervals1, new_interval1);
        std::cout << "[";
        for (auto& vec : res1)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";
        //*/

        std::vector< std::vector<int>> intervals2{ {1,5} };
        std::vector<int> new_interval2{ 2,7 };
        auto res2 = insert(intervals2, new_interval2);
        std::cout << "[";
        for (auto& vec : res2)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        std::vector< std::vector<int>> intervals3{ {1,5}, {6,8} };
        std::vector<int> new_interval3{ 5,6 };
        auto res3 = insert(intervals3, new_interval3);
        std::cout << "[";
        for (auto& vec : res3)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        std::vector< std::vector<int>> intervals4{ {1,5}, {6,8} };
        std::vector<int> new_interval4{ 0,9 };
        auto res4 = insert(intervals4, new_interval4);
        std::cout << "[";
        for (auto& vec : res4)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";

        std::vector< std::vector<int>> intervals5{ {0,0}, {2,4}, {9,9} };
        std::vector<int> new_interval5{ 0,7 };
        auto res5 = insert(intervals5, new_interval5);
        std::cout << "[";
        for (auto& vec : res5)
        {
            support::print_vec(vec);
        }
        std::cout << "]\n";
    }

}