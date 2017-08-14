#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	//·ÇµÝ¹é
	ListNode * reverseList(ListNode *pHead)
	{
		if (pHead->next == NULL)
			return pHead;
		else
		{
			ListNode *pCur=pHead;
			ListNode *pPre = NULL;
			while (pCur != NULL)
			{
				ListNode *pNext = pCur->next;
				pCur->next = pPre;
				pPre = pCur;
				pCur = pNext;
			}
			return pPre;
		}
	}
	//µÝ¹é
	ListNode * reverseList1(ListNode *pHead)
	{
		return reverseListRe(NULL, pHead);
	}
private:
	ListNode *reverseListRe(ListNode *pPre, ListNode *pCur)
	{
		if (pCur == NULL)
			return NULL;
		if (pCur->next == NULL)
		{
			pCur->next = pPre;
			return pCur;
		}
		ListNode *pNext = pCur->next;
		pCur->next = pPre;
		ListNode *pNewHead = reverseListRe(pCur, pNext);
		return pNewHead;
	}
};

#endif