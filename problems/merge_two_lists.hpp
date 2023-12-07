#pragma

#include "list_structures.hpp"

struct NodePair
{
    ListNode* fst;
    ListNode* snd;
};

NodePair nextStep(ListNode** dest, ListNode* src)
{
    *dest = new ListNode(src->val);
    return NodePair{ (*dest)->next, src->next };
}

void pushRest(ListNode* dest, ListNode* src)
{
    while (src)
    {
        dest->next = new ListNode(src->val);
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

    ListNode *res = nullptr, *res_head = nullptr;
    ListNode *cur_fst = list1, *cur_snd = list2;
    if (cur_fst->val <= cur_snd->val)
    {
        res = new ListNode(cur_fst->val);
        cur_fst = cur_fst->next;
    }
    else
    {
        res = new ListNode(cur_snd->val);
        cur_snd = cur_snd->next;
    }
    res_head = res;
    while (cur_fst && cur_snd)
    {
        if (cur_fst->val <= cur_snd->val)
        {
            res->next = new ListNode(cur_fst->val);
            cur_fst = cur_fst->next;
        }
        else
        {
            res->next = new ListNode(cur_snd->val);
            cur_snd = cur_snd->next;
        }
        res = res->next;
    }
    pushRest(res, (cur_fst ? cur_fst : cur_snd ));
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

    void test4()
    {
        ListNode node1(2);
        ListNode node2(1);
        print_list(mergeTwoLists(&node1, &node2));
    }

    void run_tests()
    {
        test1();
        std::cout << "\n";
        test4();
/*        std::cout << "\n";
        test2();
        std::cout << "\n";
        test3();*/
    }
}