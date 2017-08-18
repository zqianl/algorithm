#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;
	ListNode(int x) :data(x), next(NULL){}
};

class Solution{
public:
	ListNode *mergeList(ListNode *head1, ListNode *head2)
	{
		if (head1 == NULL)
		{
			return head2;
		}
		if (head2 == NULL)
		{
			return head1;
		}
		ListNode *mergeHead = NULL;
		if (head1->data > head2->data)
		{
			mergeHead = head2;
			mergeHead->next = mergeList(head1, head2->next);
		}
		else
		{
			mergeHead = head1;
			mergeHead->next = mergeList(head1->next, head2);
		}
		return mergeHead;
	}
	void printMergeList(ListNode *mergeHead)
	{
		ListNode *p = mergeHead;
		while (p != NULL)
		{
			cout << p->data <<" ";
			p = p->next;
		}
	}
	void destoryMergeList(ListNode *mergeHead)
	{
		ListNode *p = mergeHead;
		ListNode *q = NULL;
		while (p != NULL)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
};



#endif