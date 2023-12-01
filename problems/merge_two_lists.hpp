#pragma

#include "list_structures.hpp"

void pushRest(ListNode* dest, ListNode* src)
{
    ListNode* dest_next = nullptr;
    while (src)
    {
        dest = src;
        dest = dest->next;
        src = src->next;
    }
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;

    if (!list2)
        return list1;

    ListNode* res = nullptr, * res_head = res;
    ListNode* cur_fst = list1, * cur_snd = list2;
    int fst_val = 0, snd_val = 0;
    while (cur_fst && cur_snd)
    {
        if (cur_fst->val >= cur_snd->val)
        {
            res = cur_fst;
            cur_fst = cur_fst->next;
        }
        else
        {
            res = cur_snd;
            cur_snd = cur_snd->next;
        }
        res = res->next;
    }
    if (cur_fst)
    {
        pushRest(res, cur_fst);
    }
    else
    {
        pushRest(res, cur_snd);
    }
    return res_head;
}

namespace merge_lists
{

    void test1()
    {
        ListNode node1(4);
        ListNode node2(2, &node1);
        ListNode node3(1, &node2);

        ListNode node4(4);
        ListNode node5(3, &node4);
        ListNode node6(1, &node5);

        print_list(mergeTwoLists(&node3, &node6));
    }

    void test2()
    {
        print_list(mergeTwoLists(nullptr, nullptr));
    }

    void test3()
    {
        ListNode node1(0);
        print_list(mergeTwoLists(nullptr, &node1));
    }

    void run_tests()
    {
        test1();
        std::cout << "\n";
        test2();
        std::cout << "\n";
        test3();
    }
}