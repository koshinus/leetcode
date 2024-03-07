#pragma

#include "list_structures.hpp"

void pushRest(ListNode* dest, ListNode* src)
{
    while (src)
    {
        dest = pushNode(&src, &dest->next);
    }
}

ListNode* mergeTwoLists_(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    ListNode *res = nullptr, *res_head = nullptr;
    pushNode(list1->val <= list2->val ? &list1 : &list2, &res);
    res_head = res;
    while (list1 && list2)
    {
        res = pushNode( list1->val <= list2->val ? &list1 : &list2, &res->next );
    }
    ListNode* rest_list = list1 ? list1 : list2;
    while (rest_list)
    {
        res = pushNode( &rest_list, &res->next );
    }
    return res_head;
}

std::vector<ListNode> m_list;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    m_list.clear();
    ListNode** cur_node = list1->val <= list2->val ? &list1 : &list2;
    m_list.emplace_back((*cur_node)->val);
    (*cur_node) = (*cur_node)->next;
    while (true)
    {
        if ( !(list1 && list2) ) cur_node = list1 ? &list1 : &list2;
        else cur_node = list1->val <= list2->val ? &list1 : &list2;
        if (!*cur_node) break;
        m_list.emplace_back( (*cur_node)->val );
        //m_list[m_list.size() - 2].next = *cur_node;
        (*cur_node) = (*cur_node)->next;
    }
    for (int i = 0; i < m_list.size() - 1; i++)
    {
        m_list[i].next = &m_list[i + 1];
    }
    return m_list.data();
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
        test2();
        std::cout << "\n";
        test3();
        std::cout << "\n";
        test4();
        //*/
    }
}