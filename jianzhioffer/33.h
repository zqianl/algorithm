#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;
	ListNode(int x) :data(x), next(NULL){}
};

class Solution{
public:
	void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
	{
		if (pToBeDeleted->next != NULL)
		{
			ListNode *pNext = pToBeDeleted->next;
			pToBeDeleted->data = pToBeDeleted->next->data;
			pToBeDeleted->next = pToBeDeleted->next->next;
			delete pNext;
			pNext = NULL;
		}
		else if (*pListHead == pToBeDeleted)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			*pListHead = NULL;
		}
		else
		{
			ListNode *pNode = *pListHead;
			while (pNode->next != pToBeDeleted)
				pNode = pNode->next;
			pNode->next = NULL;
			delete pToBeDeleted;
			pToBeDeleted = NULL;
		}
	}
};

#endif