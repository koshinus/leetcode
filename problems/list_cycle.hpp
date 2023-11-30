#pragma once

#include "list_structures.hpp"

// TODO: repeat after time
bool hasCycle(ListNode* head)
{
    ListNode* fst = head, * snd = head;
    while (fst && fst->next)
    {
        fst = fst->next->next;
        snd = snd->next;
        if (fst == snd)
        {
            return true;
        }
    }
    return false;
}

namespace list_cycle
{
    void run_tests()
    {
    }
}

/*
* Status: accepted
* Runtime: 7ms, Beats 88.66%
* Memory: 8.47 Mb, Beats 56.2%
*/
