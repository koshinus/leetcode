#include <iostream>
#include "problems/support_func.hpp"

#include "problems/counting_bits.hpp"
#include "problems/reverse_bits.hpp"
#include "problems/missing_number.hpp"
#include "problems/sum_of_two_ints.hpp"

#include "problems/rotate_image.hpp"
#include "problems/set_matrix_zeros.hpp"
#include "problems/spiral_matrix.hpp"

int main()
{
	//support::print_vec( countBits( 5 ) );
	/*
	auto answer = reverseBits(4294967293);
	support::print_val_binary(answer);
	std::cout << "\n"  << answer;
	*/
	/*
	auto vec1 = std::vector<int>{ 3, 0, 1 };
	auto vec2 = std::vector<int>{ 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int res = missingNumber(vec2);
	*/
	/*
	std::cout << getSum(2, 3);
	std::cout << "new num\n";
	std::cout << getSum(2, 2);
	std::cout << "new num\n";
	std::cout << getSum(20, 28);
	*/
	/*
	std::vector<std::vector<int>> mat{ {1,2,3}, {4,5,6}, {7,8,9} };
	std::vector<std::vector<int>> mat1{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	rotate(mat);
	std::cout << "--------\n";
	rotate(mat1);
	*/
	/*
	std::vector<std::vector<int>> mat{ {1,1,1}, {1,0,1}, {1,1,1} };
	std::vector<std::vector<int>> mat1{ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} };
	setZeroes(mat);
	std::cout << "--------\n";
	setZeroes(mat1);
	*/
	std::vector<std::vector<int>> mat{ {1,2,3}, {4,5,6}, {7,8,9} };
	support::print_vec(spiralOrder(mat));
	std::cout << "-----------------\n";
	std::vector<std::vector<int>> mat1{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	support::print_vec(spiralOrder(mat1));
	return 0;
}