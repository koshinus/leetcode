#pragma once

#include <vector>
#include "support_func.hpp"

void rotate(std::vector<std::vector<int>>& matrix)
{
	support::print_matrix(matrix);
	std::cout << "\n";
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); ++i) 
	{
		for (int j = i + 1; j < matrix[i].size(); ++j)
			std::swap(matrix[i][j], matrix[j][i]);
	}
	support::print_matrix(matrix);
}


/*
* Status: accepted
* Runtime: 0ms?, Beats 100%
* Memory: 7.4 Mb, Beats 25.46%
*/