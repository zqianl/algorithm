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
	bool SubTreeOrNot(const TreeNode *pRootA, const TreeNode *pRootB)
	{
		bool isSubTree = false;
		if (pRootA != NULL && pRootB != NULL)
		{
			if (pRootA->data == pRootB->data)
				isSubTree = DecideSubTree(pRootA, pRootB);
			if (!isSubTree)
				isSubTree = SubTreeOrNot(pRootA->lc, pRootB);
			if (!isSubTree)
				isSubTree = SubTreeOrNot(pRootB->rc, pRootB);
		}
		return isSubTree;
	}
private:
	bool DecideSubTree(const TreeNode *pRootA, const TreeNode *pRootB)
	{
		if (pRootB == NULL)
			return true;
		if (pRootA == NULL)
			return false;
		if (pRootA->data != pRootB->data)
			return false;
		return DecideSubTree(pRootA->lc, pRootB->lc) &&
			DecideSubTree(pRootA->rc, pRootB->rc);
	}
};

#endif