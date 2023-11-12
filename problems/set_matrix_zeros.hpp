#pragma once

#include <vector>
#include <set>

#include "support_func.hpp"

void setRowZeros(std::vector<std::vector<int>>& matrix, int row)
{
	for (int i = 0; i < matrix[row].size(); i++)
	{
		matrix[row][i] = 0;
	}
}

void setColZeros(std::vector<std::vector<int>>& matrix, int col)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i][col] = 0;
	}
}

void setColAndRowZeros(std::vector<std::vector<int>>& matrix, int row, int col)
{
	setRowZeros(matrix, row);
	setColZeros(matrix, col);
}

void setZeroes1(std::vector<std::vector<int>>& matrix)
{
	std::set<int> visited_rows, visited_cols;
	support::print_matrix(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0 && 
				!support::container_contains_elem(visited_rows, i) &&
				!support::container_contains_elem(visited_cols, j) )
			{
				setColAndRowZeros(matrix, i, j);
				visited_rows.insert(i);
				visited_cols.insert(j);
			}
		}
	}
	support::print_matrix(matrix);
}


void setZeroes(std::vector<std::vector<int>>& matrix)
{
	support::print_matrix(matrix);
	std::set<int> visited_rows, visited_cols;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				visited_rows.insert(i);
				visited_cols.insert(j);
			}
		}
	}
	for (int i : visited_rows)
	{
		setRowZeros(matrix, i);
	}
	for (int i : visited_cols)
	{
		setColZeros(matrix, i);
	}
	support::print_matrix(matrix);
}

namespace set_zeros
{

void run_tests()
{
    std::vector<std::vector<int>> mat{ {1,1,1}, {1,0,1}, {1,1,1} };
    std::vector<std::vector<int>> mat1{ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} };
    setZeroes(mat);
    std::cout << "--------\n";
    setZeroes(mat1);
}

}

/*
* Status: accepted
* Runtime: 7ms, Beats 91.7%
* Memory: 13.9 Mb, Beats 18.02%
*/
