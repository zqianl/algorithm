#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *lc;
	TreeNode *rc;
	TreeNode(int x) :data(x), lc(NULL), rc(NULL){}
};

class Solution{
public:
	void PrintTopToBottom(TreeNode *pRoot)
	{
		if (pRoot == NULL)
			return;
		deque<TreeNode *>dequeTree;
		dequeTree.push_back(pRoot);
		while (dequeTree.size())
		{
			TreeNode *pNode = dequeTree.front();
			dequeTree.pop_front();
			cout << pNode->data <<" ";
			if (pNode->lc != NULL)
				dequeTree.push_back(pNode->lc);
			if (pNode->rc != NULL)
				dequeTree.push_back(pNode->rc);
		}
	}
};

#endif