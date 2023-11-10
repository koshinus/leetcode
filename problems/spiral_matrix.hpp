#pragma once

#include <vector>

#include "support_func.hpp"

enum class current_direction: std::uint8_t
{
	RIGHT,
	DOWN,
	LEFT,
	UP
};

current_direction next_direction(current_direction direction)
{
	switch (direction)
	{
	case current_direction::RIGHT: return current_direction::DOWN;
	case current_direction::DOWN: return current_direction::LEFT;
	case current_direction::LEFT: return current_direction::UP;
	case current_direction::UP:
	default: return current_direction::RIGHT;
	}
}

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
	std::vector<int> result;
	result.reserve(matrix.size() * matrix[0].size());
	current_direction cur_dir = current_direction::RIGHT;
	int left = 0, right = matrix[ 0 ].size() - 1, top = 0, down = matrix.size() - 1;
	while (left <= right && top <= down)
	{
		switch (cur_dir)
		{
		case current_direction::RIGHT:
		{
			for (int i = left; i <= right; i++)
			{
				result.push_back(matrix[top][i]);
			}
			top++;
			break;
		}
		case current_direction::DOWN:
		{
			for (int i = top; i <= down; i++)
			{
				result.push_back(matrix[i][right]);
			}
			right--;
			break;
		}
		case current_direction::LEFT:
		{
			for (int i = right; i >= left; i--)
			{
				result.push_back(matrix[down][i]);
			}
			down--;
			break;
		}
		case current_direction::UP:
		{
			for (int i = down; i >= top; i--)
			{
				result.push_back(matrix[i][left]);
			}
			left++;
			break;
		}
		}
		cur_dir = next_direction(cur_dir);
	}
	return result;
}

/*
* Status: accepted
* Runtime: 0ms?, Beats 100%
* Memory: 7.31 Mb, Beats 18.09%
*/