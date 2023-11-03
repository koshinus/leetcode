#include <iostream>
#include "problems/support_func.hpp"

#include "problems/counting_bits.hpp"
#include "problems/reverse_bits.hpp"
#include "problems/missing_number.hpp"
#include "problems/sum_of_two_ints.hpp"

#include "problems/rotate_image.hpp"
#include "problems/set_matrix_zeros.hpp"
#include "problems/spiral_matrix.hpp"
#include "problems/word_search.hpp"

#include "problems/two_sum.hpp"
#include "problems/contains_duplicate.hpp"
#include "problems/search_in_rotated_array.hpp"
#include "problems/minimum_in_rotated.hpp"

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
	/*
	std::vector<std::vector<int>> mat{ {1,2,3}, {4,5,6}, {7,8,9} };
	support::print_vec(spiralOrder(mat));
	std::cout << "-----------------\n";
	std::vector<std::vector<int>> mat1{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	support::print_vec(spiralOrder(mat1));
	*/
	/*
	std::vector<std::vector<char>> mat{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
	std::string word = "SEE";
	support::print_matrix( mat );
	std::cout << exist( mat, word );
	*/
	/*
	std::vector<int> vec{ 2, 7, 11, 15 };
	support::print_vec( twoSum( vec, 9 ) );
	std::cout << "\n";
	std::vector<int> vec1{ 3, 2, 4 };
	support::print_vec(twoSum(vec1, 6));
	std::cout << "\n";
	std::vector<int> vec2{ 3, 3 };
	support::print_vec(twoSum(vec2, 6));
	*/
	/*
	std::vector<int> dups{ 1,2,3,4 };
	std::cout << containsDuplicate( dups ) << "\n";
	*/
	/*
	std::vector<int> vec{5,6,7,8};
	std::cout << search(vec, 7) << "\n";
	std::vector<int> vec1{1,2,3,4};
	std::cout << search(vec1, -1);
	//*/
	/*
	std::vector<int> vec{ 3,4,1,2 };
	std::cout << search(vec, 1) << "\n";
	std::vector<int> vec1{ 4,5,6,7,0,1,2 };
	std::cout << search(vec1, 4) << "\n";
	std::vector<int> vec2{ 1,3 };
	std::cout << search(vec2, 3) << "\n";
	std::vector<int> vec3{ 1,3,5,6,7,89,98 };
	std::cout << bin_search(vec3, 98, 0, vec3.size());
	std::vector<int> vec4{ 3,5,1 };
	std::cout << search(vec4, 5) << "\n";
	std::vector<int> vec5{ 4,5,6,7,0,1,2 };
	std::cout << search(vec5, 7) << "\n";
	//*/

	/*
	std::vector<int> vec5{ 4,5,6,7,0,1,2 };
	std::cout << findMin(vec5) << "\n";
	//*/
	return 0;
}