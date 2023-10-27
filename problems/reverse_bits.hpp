#pragma once

#include <cstdint>

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

/*
* Status: accepted
* Runtime: 8ms, Beats 8.41%
* Memory:  6.39Mb, Beats 32.47%
*/