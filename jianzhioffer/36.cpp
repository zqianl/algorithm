#include "36.h"

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

void PrintLDR(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->lc != NULL)
		PrintLDR(pRoot->lc);
	cout << pRoot->data << " ";
	if (pRoot->rc != NULL)
		PrintLDR(pRoot->rc);
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
	TreeNode *pRootA = CreateTreeA(treeA);
	PrintLDR(pRootA);
	cout << endl;
	Solution s;
	s.MirrorTree(pRootA);
	PrintLDR(pRootA);
	cout << endl;
	DestoryTree(pRootA);
	system("pause");
	return 0;
}