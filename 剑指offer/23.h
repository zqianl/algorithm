#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	void printList(ListNode *node)
	{
		if (node == NULL)
			return;
		else
		{
			printList(node->next);
			cout << node->val << endl;
		}
	}
};

#endif