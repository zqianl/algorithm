#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

struct BSTNode{
	int data;
	BSTNode *lc;
	BSTNode *rc;
	BSTNode(int x) :data(x), lc(NULL), rc(NULL){}
};

class Solution{
public:
	BSTNode *Convert(BSTNode *pRoot)
	{
		if (pRoot == NULL)
			return NULL;
		if (pRoot->lc == NULL&&pRoot->rc == NULL)
			return pRoot;
		BSTNode *pLast = NULL;
		ConvertNode(pRoot, &pLast);
		BSTNode *pHead = pLast;
		while (pHead->lc != NULL)
			pHead = pHead->lc;
		return pHead;
	}
private:
	void ConvertNode(BSTNode *pRoot, BSTNode **pLast)
	{
		if (pRoot == NULL)
			return;
		if (pRoot->lc != NULL)
			ConvertNode(pRoot->lc, pLast);
		pRoot->lc = *pLast;
		if (*pLast != NULL)
			(*pLast)->rc = pRoot;
		*pLast = pRoot;
		if (pRoot->rc != NULL)
			ConvertNode(pRoot->rc, pLast);
	}
};

#endif