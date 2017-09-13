#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *lc;
	TreeNode *rc;
	TreeNode(int x) :data(x), lc(NULL), rc(NULL){}
};

void ConnectTreeNode(TreeNode *pRoot, TreeNode *lc, TreeNode *rc)
{
	if (pRoot == NULL)
		return;
	if (lc != NULL)
		pRoot->lc = lc;
	if (rc != NULL)
		pRoot->rc = rc;
}

void Destory(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->lc != NULL)
		Destory(pRoot->lc);
	if (pRoot->rc != NULL)
		Destory(pRoot->rc);
	delete pRoot;
	pRoot = NULL;
}

bool GetNodePath(TreeNode *pRoot, TreeNode *pNode, list<TreeNode *>&path)
{
	if (pRoot == pNode)
		return true;
	path.push_back(pRoot);
	bool found = false;
	if (pRoot->lc != NULL)
		found = GetNodePath(pRoot->lc, pNode, path);
	if (pRoot->rc != NULL && !found)
		found = GetNodePath(pRoot->rc, pNode, path);
	if (!found)
		path.pop_back();
	return found;
}

TreeNode *GetLastCommonNode(list<TreeNode *> &path1, list<TreeNode *> &path2)
{
	list<TreeNode *>::iterator iterPath1 = path1.begin();
	list<TreeNode *>::iterator iterPath2 = path2.begin();
	TreeNode *lastCommonNode = NULL;
	while (iterPath1 != path1.end() && iterPath2 != path2.end() && *iterPath1 == *iterPath2)
	{
		lastCommonNode = *iterPath1;
		iterPath1++;
		iterPath2++;
	}
	return lastCommonNode;
}

TreeNode *GetLastCommonParent(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2)
{
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;
	list<TreeNode *>path1;
	GetNodePath(pRoot, pNode1, path1);
	list<TreeNode *>path2;
	GetNodePath(pRoot, pNode2, path2);
	return GetLastCommonNode(path1, path2);
}

void Test1()
{
	vector<int>vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<TreeNode *>vecTreeNode;
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		vecTreeNode.push_back(new TreeNode(vec[i]));
	}
	ConnectTreeNode(vecTreeNode[0], vecTreeNode[1], vecTreeNode[2]);
	ConnectTreeNode(vecTreeNode[1], vecTreeNode[3], vecTreeNode[4]);
	ConnectTreeNode(vecTreeNode[2], vecTreeNode[5], vecTreeNode[6]);
	ConnectTreeNode(vecTreeNode[3], vecTreeNode[7], NULL);
	ConnectTreeNode(vecTreeNode[4], vecTreeNode[8], NULL);
	TreeNode *result = GetLastCommonParent(vecTreeNode[0], vecTreeNode[7], vecTreeNode[8]);
	if (result == vecTreeNode[1])
		cout << "true!" << endl;
	else
		cout << "false!" << endl;
	Destory(vecTreeNode[0]);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}