#include "35.h"

void ConnectTreeNode(TreeNode *pRoot, TreeNode *lc, TreeNode *rc)
{
	if (pRoot == NULL)
		return;
	if (lc != NULL)
		pRoot->lc = lc;
	if (rc != NULL)
		pRoot->rc = rc;
}

TreeNode *CreateTreeA(const vector<int> &data)
{
	if (data.size() == 0)
		return NULL;
	vector<TreeNode *> vecTreeNode;
	for (unsigned int i = 0; i < data.size(); ++i)
		vecTreeNode.push_back(new TreeNode(data[i]));
	ConnectTreeNode(vecTreeNode[0], vecTreeNode[1], vecTreeNode[2]);
	ConnectTreeNode(vecTreeNode[1], vecTreeNode[3], vecTreeNode[4]);
	ConnectTreeNode(vecTreeNode[4], vecTreeNode[5], vecTreeNode[6]);
	return vecTreeNode[0];
}

TreeNode *CreateTreeB(const vector<int> &data)
{
	if (data.size() == 0)
		return NULL;
	vector<TreeNode *> vecTreeNode;
	for (unsigned int i = 0; i < data.size(); ++i)
		vecTreeNode.push_back(new TreeNode(data[i]));
	ConnectTreeNode(vecTreeNode[0], vecTreeNode[1], vecTreeNode[2]);
	return vecTreeNode[0];
}

void DestoryTree(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->lc != NULL)
		DestoryTree(pRoot->lc);
	if (pRoot->rc != NULL)
		DestoryTree(pRoot->rc);
	delete pRoot;
	pRoot = NULL;
}

int main(int argc, char **argv)
{
	vector<int> treeA = { 8, 8, 7, 9, 2, 4, 7 };
	vector<int> treeB = { 8, 9, 2 };
	TreeNode *pRootA = CreateTreeA(treeA);
	TreeNode *pRootB = CreateTreeB(treeB);
	Solution s;
	bool bIsSubTreeOfA = s.SubTreeOrNot(pRootA, pRootB);
	cout << bIsSubTreeOfA << endl;
	DestoryTree(pRootA);
	DestoryTree(pRootB);
	system("pause");
	return 0;
}