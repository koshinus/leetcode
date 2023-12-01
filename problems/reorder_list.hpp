#pragma once

#include <iostream>

#include "list_structures.hpp"

ListNode* reorderOnce(ListNode* head)
{
    ListNode* next_elem = head->next, * tail = head, * prev_tail = head;

    if (!next_elem || !next_elem->next)
        return nullptr;

    while (tail->next)
    {
        prev_tail = tail;
        tail = tail->next;
    }
    prev_tail->next = nullptr;
    head->next = tail;
    tail->next = next_elem;
    return next_elem;
}

void reorderList(ListNode* head)
{
    auto next_head = head;
    while (next_head)
    {
        next_head = reorderOnce(next_head);
    }
}

namespace reorder_list
{

    void test1()
    {
        ListNode node1(5);
        ListNode node2(4, &node1);
        ListNode node3(3, &node2);
        ListNode node4(2, &node3);
        ListNode node5(1, &node4);

        ListNode* node = &node5;
        print_list(node);
        std::cout << "\n";
        reorderList(node);
        print_list(node);
    }

    void test2()
    {
        ListNode node1(4);
        ListNode node2(3, &node1);
        ListNode node3(2, &node2);
        ListNode node4(1, &node3);

        ListNode* node = &node4;
        print_list(node);
        std::cout << "\n";
        reorderList(node);
        print_list(node);
    }

    void run_tests()
    {
        test1();
        std::cout << "\n";
        test2();
    }
}


/*
* Status: accepted
* Runtime: 528ms, Beats 6.3%
* Memory: 18.09 Mb, Beats 73.95%
*/
