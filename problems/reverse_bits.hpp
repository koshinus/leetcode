#pragma once

#include <iostream>
#include <cstdint>
#include "support_func.hpp"

std::uint32_t reverseBits(std::uint32_t n)
{
    std::uint32_t res = 0;
    int digits_in_number = 32;
    for (int i = 0; i < digits_in_number; i++)
    {
        res <<= 1;
        if (n > 0)
        {
            res |= (n & 1);
            n >>= 1;
        }
    }
    return res;
}

namespace reverse_bits
{

void run_tests()
{
    auto answer = reverseBits(4294967293);
    support::print_val_binary(answer);
    std::cout << "\n"  << answer;
}

}

/*
* Status: accepted
* Runtime: 8ms, Beats 8.41%
* Memory:  6.39Mb, Beats 32.47%
*/
