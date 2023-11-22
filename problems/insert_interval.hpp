#pragma once

#include <vector>

bool value_is_in_interval( const std::vector<int> interval, int val )
{
    return (interval[0] <= val) && (interval[1] >= val);
}

std::vector<std::vector<int>> merge_last_pos(std::vector<std::vector<int>>&& intervals, std::vector<int>&& newInterval)
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

std::vector<std::vector<int>> merge_interval(std::vector<std::vector<int>>&& intervals, std::vector<int>&& newInterval,
                                                int left_interval_pos, int right_interval_pos)
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
    intervals.insert( intervals.erase( it_begin + left_interval_pos, it_begin + right_interval_pos ), interval_for_insert );
    return std::move( intervals );
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    int left_pos = 0, right_pos = intervals.size();
    for ( int i = 0; i < intervals.size(); i++ )
    {
        if ( value_is_in_interval( intervals[ i ], newInterval[0] ) )
        {
            left_pos = i;
            break;
        }
    }
    for ( int i = left_pos; i < intervals.size(); i++ )
    {
        if ( value_is_in_interval( intervals[ i ], newInterval[1] ) )
        {
            right_pos = i;
            break;
        }
    }
    if (right_pos == intervals.size())
    {
        return merge_last_pos( std::move( intervals ), std::move( newInterval ) );
    }
    else
    {
        return merge_interval( std::move( intervals ), std::move( newInterval ), left_pos, right_pos );
    }
}


namespace insert_interval
{

    void run_tests()
    {
        std::vector< std::vector<int>> intervals{ {1,3}, {6,9} };
        std::vector<int> new_interval{ 2,5 };
        auto res1 = insert( intervals, new_interval );

        std::vector< std::vector<int>> intervals1{ {1,2},{3,5},{6,7},{8,10},{12,16} };
        std::vector<int> new_interval1{ 4,8 };
        auto res2 = insert(intervals1, new_interval1);
    }

}