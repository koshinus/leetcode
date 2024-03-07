#pragma once

#include "list_structures.hpp"

int getNextSource(const std::vector<ListNode*>& lists)
{
    int min_val = INT_MAX;
    int res = -1;
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode* list = lists[i];
        if (!list)
            continue;
        if (list->val < min_val)
        {
            min_val = list->val;
            res = i;
        }
    }
    return res;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if ( lists.empty() )
        return nullptr;

    ListNode *res = nullptr, *res_head = nullptr;
    int src_idx = getNextSource(lists);
    if ( src_idx == -1 )
        return nullptr;

    res = new ListNode(lists[src_idx]->val);
    lists[src_idx] = lists[src_idx]->next;
    res_head = res;
    
    while ( true )
    {
        src_idx = getNextSource(lists);
        if ( src_idx == -1 )
            return res_head;
        res->next = new ListNode(lists[src_idx]->val);
        lists[src_idx] = lists[src_idx]->next;
        res = res->next;
    }
    return res_head;
}

namespace merge_k_lists
{
    void test1()
    {
        ListNode node1(5);
        ListNode node2(4, &node1);
        ListNode node3(1, &node2);

        ListNode node4(4);
        ListNode node5(3, &node4);
        ListNode node6(1, &node5);

        ListNode node7(6);
        ListNode node8(2, &node7);

        std::vector< ListNode* > vec{ &node3, &node6, &node8 };

        print_list( mergeKLists( vec ) );
    }

    void test2()
    {
        ListNode node1(1);

        std::vector< ListNode* > vec{ nullptr, &node1 };
        print_list( mergeKLists( vec ) );
    }

    void test3()
    {
        std::vector<ListNode*> vec{ nullptr };
        print_list( mergeKLists( vec ) );
    }

    void test4()
    {
        std::vector<ListNode*> vec;
        print_list( mergeKLists( vec ) );
    }

    void test5()
    {
        std::vector<ListNode*> vec{ nullptr, nullptr };
        print_list( mergeKLists( vec ) );
    }

    void run_tests()
    {
        test1();
        std::cout << "\n";
        test2();
        std::cout << "\n";
        test3();
        std::cout << "\n";
        test4();
        std::cout << "\n";
        test5();
    }
}