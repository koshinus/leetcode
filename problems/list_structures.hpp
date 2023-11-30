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

void print_list(ListNode* head)
{
	while (head)
	{
		std::cout << head->val << "->";
		head = head->next;
	}
}