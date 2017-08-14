#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *lc;
	TreeNode *rc;
	TreeNode(int x) :val(x), lc(NULL), rc(NULL){}
};

class Solution{
public:
	TreeNode *root = NULL;
	bool RebuildTree(vector<int>pre, vector<int>inv)
	{
		RebuildBinTree(root, pre, inv);
		return canRebuild;
	}
	void behTraverse(TreeNode *node)
	{
		if (node == NULL)
			return;
		behTraverse(node->lc);
		behTraverse(node->rc);
		cout << node->val << " ";
	}
	void destory(TreeNode *&root)
	{
		if (root == NULL)
			return;
		if (root->lc)
			destory(root->lc);
		if (root->rc)
			destory(root->rc);
		delete root;
	}
private:
	void RebuildBinTree(TreeNode *&root, vector<int>pre, vector<int>inv)
	{
		int num = pre.size();
		int i;
		for (i = 0; i < num; ++i)
		{
			if (*(inv.begin() + i) == *(pre.begin()))
				break;
		}
		if (i == num)
		{
			canRebuild = false;
			return;
		}
		root = new TreeNode(*(pre.begin()));
		if (i != 0)
		{
			vector<int>vec1(pre.begin() + 1, pre.begin() + i + 1);
			vector<int>vec2(inv.begin() , inv.begin() + i);
			RebuildBinTree(root->lc, vec1, vec2);
		}
		if (i != num - 1)
		{
			vector<int>vec3(pre.begin() + i + 1, pre.end());
			vector<int>vec4(inv.begin() + i + 1, inv.end());
			RebuildBinTree(root->rc, vec3, vec4);
		}
	}
	bool canRebuild = true;
	
};

#endif