#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>

namespace support
{

template<typename T>
void print_vec(const std::vector<T>& vec)
{
	std::string str = "[";
	for( size_t i = 0; i < vec.size(); i++ )
	{
		str += std::to_string( vec[ i ] );
		if ( i != ( vec.size() - 1 ) )
		{
			str += ",";
		}
	}
	str += "]";
	std::cout << str << std::endl;
}
template<>
void print_vec<char>(const std::vector<char>& vec)
{
	std::string str = "[";
	for (size_t i = 0; i < vec.size(); i++)
	{
		str += char(vec[i]);
		if (i != (vec.size() - 1))
		{
			str += ",";
		}
	}
	str += "]";
	std::cout << str << std::endl;
}

template<typename T>
void print_val_binary(const T& val)
{
	constexpr int bits_in_byte = 8;
	constexpr int bitset_size = sizeof(T) * bits_in_byte;
	std::bitset<bitset_size> bset(val);
	std::cout << bset << std::endl;
}

template<typename T>
void print_val(const T& val)
{
	std::cout << val << std::endl;
}

template<typename T>
void print_matrix(const std::vector<std::vector<T>>& matrix)
{
	for (auto& row : matrix)
	{
		print_vec(row);
	}
}

template<typename T>
void print_set(const std::unordered_set<T>& set)
{
	std::string str = "{";
	int i = 0;
	for (auto elem : set)
	{
		str += std::to_string( elem.fst );
		if ( i != (set.size() - 1))
		{
			str += ",";
		}
		i++;
	}
	str += "}";
	std::cout << str << std::endl;
}

template<typename T>
std::vector<std::vector<T>> prepare_matrix(size_t n, size_t m)
{
	std::vector<std::vector<T>> matrix;
	matrix.reserve(n);
	for (size_t i = 0; i < n; i++)
	{
		matrix[i].emplace_back(std::vector(m, T()));
	}
	return matrix;
}

template<>
std::vector<std::vector<int>> prepare_matrix(size_t n, size_t m)
{
	std::vector<std::vector<int>> matrix;
	matrix.reserve(n);
	for (size_t i = 0; i < n; i++)
	{
		matrix.emplace_back(std::vector(m, 0));
	}
	return matrix;
}

template<typename ContainerT, typename ElemType>
bool container_contains_elem(const ContainerT& container, const ElemType& elem)
{
	return container.find(elem) != container.end();
}

}