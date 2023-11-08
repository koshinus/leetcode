#pragma once

#include <vector>

int get_container_area(const std::vector<int>& container, int left_border, int right_border)
{
	return std::min(container[left_border], container[right_border]) * (right_border - left_border);
}

int quadratic_solution(const std::vector<int>& container)
{
	int max_area = 0;
	int cur_area = 0;
	for (int i = 0; i < container.size(); i++)
	{
		for (int j = i; j < container.size(); j++)
		{
			cur_area = get_container_area(container, i, j);
			if (cur_area > max_area)
			{
				max_area = cur_area;
			}
		}
	}
	return max_area;
}

// TODO: understand why this works
int linear_solution(const std::vector<int>& container)
{
	int start = 0, end = container.size() - 1;
	int max_area = 0;
	while (start < end)
	{
		max_area = std::max( max_area, get_container_area(container, start, end) );
		if (container[start] < container[end])
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	return max_area;
}

int maxArea(std::vector<int>& height)
{
	return linear_solution(height);
}


/*
* Status: accepted
* Runtime: 81ms, Beats 10.98%
* Memory: 59.29 Mb, Beats 79.7%
*/