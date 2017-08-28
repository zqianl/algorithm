#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

using namespace std;

struct ComplexListNode{
	int data;
	ComplexListNode *next;
	ComplexListNode *pSibling;
	ComplexListNode(int x) :data(x), next(NULL), pSibling(NULL){}
};

class Solution{
public:
	ComplexListNode *CopyComplexList(ComplexListNode *pListHead)
	{
		CloneListNode(pListHead);
		ConnectSiblingNode(pListHead);
		return ReconnectNode(pListHead);
	}
private:
	void CloneListNode(ComplexListNode *pListHead)
	{
		if (pListHead == NULL)
			return;
		ComplexListNode *pListNode = pListHead;
		while (pListNode != NULL)
		{
			ComplexListNode *pNode = new ComplexListNode(pListNode->data);
			pNode->next = pListNode->next;
			pListNode->next = pNode;
			pListNode = pNode->next;
		}
	}
	void ConnectSiblingNode(ComplexListNode *pListHead)
	{
		if (pListHead == NULL)
			return;
		ComplexListNode *pListNode = pListHead;
		while (pListNode != NULL)
		{
			if (pListNode->pSibling != NULL)
			{
				pListNode->next->pSibling = pListNode->pSibling->next;
			}
			pListNode = pListNode->next->next;
		}
	}
	ComplexListNode *ReconnectNode(ComplexListNode *pListHead)
	{
		if (pListHead == NULL)
			return NULL;
		ComplexListNode *pNode = pListHead;
		ComplexListNode *pCloneHead = pNode->next;
		ComplexListNode *pCloneNode = pCloneHead;
		pNode->next = pCloneNode->next;
		pNode = pCloneNode->next;
		while (pNode != NULL)
		{
			pCloneNode->next = pNode->next;
			pCloneNode = pCloneNode->next;
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}
		return pCloneHead;
	}
};

#endif