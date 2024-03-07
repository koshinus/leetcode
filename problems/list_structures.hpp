#pragma once

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* pushNode(ListNode** node, ListNode** res)
{
	*res = new ListNode((*node)->val);
	(*node) = (*node)->next;
	return *res;
}

void print_list(ListNode* head)
{
	while (head)
	{
		std::cout << head->val << "->";
		head = head->next;
	}
}