#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *lc;
	TreeNode *rc;
	TreeNode(int x) :data(x), lc(NULL), rc(NULL){}
};

class Solution{
public:
	void MirrorTree(TreeNode *pRoot)
	{
		if (pRoot == NULL)
			return;
		if (pRoot->lc == NULL && pRoot->rc == NULL)
			return;

		TreeNode *pTemp = pRoot->lc;
		pRoot->lc = pRoot->rc;
		pRoot->rc = pTemp;

		if (pRoot->lc != NULL)
			MirrorTree(pRoot->lc);
		if (pRoot->rc != NULL)
			MirrorTree(pRoot->rc);
	}
};

#endif