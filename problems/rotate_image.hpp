#pragma once

#include <vector>
#include <algorithm>
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

namespace rotate_image
{

void run_tests()
{
    std::vector<std::vector<int>> mat{ {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> mat1{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    rotate(mat);
    std::cout << "--------\n";
    rotate(mat1);
}

}

/*
* Status: accepted
* Runtime: 0ms?, Beats 100%
* Memory: 7.4 Mb, Beats 25.46%
*/
