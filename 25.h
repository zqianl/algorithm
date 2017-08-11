#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode *FindLastk(ListNode *pHead,int target)
	{
		ListNode *p1 = pHead;
		ListNode *p2 = pHead;
		while (target != 0)
		{
			p2 = p2->next;
			target--;
		}
		while (p2 != NULL)
		{
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;
	}
};

#endif