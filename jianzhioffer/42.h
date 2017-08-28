#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *lc;
	TreeNode *rc;
	TreeNode(int x) :data(x), lc(NULL), rc(NULL){}
};

class Solution{
public:
	void FindPath(TreeNode *pRoot,int sum)
	{
		if (pRoot == NULL)
			return;
		int currSum = 0;
		vector<int> path;
		FindPath(pRoot, sum, currSum, path);
	}
private:
	void FindPath(TreeNode *pRoot, int sum, int currSum, vector<int> &path)
	{
		currSum += pRoot->data;
		path.push_back(pRoot->data);
		if (pRoot->lc == NULL&&pRoot->rc == NULL&&currSum == sum)
		{
			for (auto i = path.begin(); i < path.end(); ++i)
				cout << *i << " ";
			cout << endl;
		}
		if (pRoot->lc != NULL)
			FindPath(pRoot->lc, sum, currSum, path);
		if (pRoot->rc != NULL)
			FindPath(pRoot->rc, sum, currSum, path);
		path.pop_back();
	}
};

#endif