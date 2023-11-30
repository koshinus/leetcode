#pragma once

#include "list_structures.hpp"

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* original_head = head, * prev = nullptr;
    int list_size = 0;
    while (head)
    {
        list_size++;
        head = head->next;
    }
    if (list_size == 1)
    {
        return nullptr;
    }
    int n_from_start = list_size - n, i = 0;
    head = original_head;
    if (n_from_start == 0)
    {
        head = head->next;
        return head;
    }

    while (i != n_from_start)
    {
        prev = head;
        head = head->next;
        i++;
    }
    prev->next = head->next;
    head = original_head;
    return head;
}

namespace remove_nth
{

    void fst_test()
    {
        ListNode node1(5);
        ListNode node2(4, &node1);
        ListNode node3(3, &node2);
        ListNode node4(2, &node3);
        ListNode node5(1, &node4);
        print_list(&node5);

        removeNthFromEnd(&node5, 2);
        print_list(&node5);
    }
    
    void snd_test()
    {

    }

    void thd_test()
    {

    }

    void run_tests()
    {
        fst_test();
        snd_test();
        thd_test();
    }

}

/*
* Status: accepted
* Runtime: 0ms?, Beats 100%
* Memory: 11.0 Mb, Beats 73.58%
*/
