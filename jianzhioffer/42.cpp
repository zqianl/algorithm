#include "42.h"

void ConnectTreeNode(TreeNode *pRoot, TreeNode *lc, TreeNode *rc)
{
	if (pRoot == NULL)
		return;
	if (lc != NULL)
		pRoot->lc = lc;
	if (rc != NULL)
		pRoot->rc = rc;
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

void Test(char *testName, TreeNode *pRoot,int sum)
{
	cout << testName << " starts: " << endl;
	Solution s;
	s.FindPath(pRoot, sum);
}

void Test1()
{
	int sum = 22;
	vector<int>data = { 10, 5, 12, 4, 7 };
	vector<TreeNode *>vecTreeNode;
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		vecTreeNode.push_back(new TreeNode(data[i]));
	}
	ConnectTreeNode(vecTreeNode[0], vecTreeNode[1], vecTreeNode[2]);
	ConnectTreeNode(vecTreeNode[1], vecTreeNode[3], vecTreeNode[4]);
	Test("Test1", vecTreeNode[0],sum);
	DestoryTree(vecTreeNode[0]);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}