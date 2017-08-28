#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

struct ListNode{
	int data;
	ListNode *pNext;
	ListNode(int x) :data(x), pNext(NULL){}
};

class Solution{
public:
	ListNode *FindFistCommonNode(ListNode *pHead1, ListNode *pHead2)
	{
		unsigned int lengthList1 = GetLength(pHead1);
		unsigned int lengthList2 = GetLength(pHead2);
		int diffLength = lengthList1 - lengthList2;
		ListNode *pHeadLong = pHead1;
		ListNode *pHeadShort = pHead2;
		if (diffLength < 0)
		{
			pHeadLong = pHead2;
			pHeadShort = pHead1;
			diffLength = -diffLength;
		}
		while (diffLength != 0)
		{
			pHeadLong = pHeadLong->pNext;
			diffLength--;
		}
		while (pHeadLong != pHeadShort&&pHeadLong!=NULL)
		{
			pHeadLong = pHeadLong->pNext;
			pHeadShort = pHeadShort->pNext;
		}
		if (pHeadLong != NULL)
			return pHeadLong;
		else
			return NULL;
	}
private:
	unsigned int GetLength(ListNode *pHead)
	{
		if (pHead == NULL)
			return 0;
		unsigned int count = 0;
		ListNode *pNode = pHead;
		while (pNode != NULL)
		{
			++count;
			pNode = pNode->pNext;
		}
		return count;
	}
};


#endif