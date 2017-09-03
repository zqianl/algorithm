#include<iostream>
#include<stack>
#include<queue>
#include<vector>

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

TreeNode * CreateTree(const vector<int>&vec)
{
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
	return vecTreeNode[0];
}

void TravPreRecu(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	cout << pRoot->data << " ";
	TravPreRecu(pRoot->lc);
	TravPreRecu(pRoot->rc);
}

void TravInRecu(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	TravInRecu(pRoot->lc);
	cout << pRoot->data << " ";
	TravInRecu(pRoot->rc);
}

void TravPostRecu(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	TravPostRecu(pRoot->lc);
	TravPostRecu(pRoot->rc);
	cout << pRoot->data << " ";
}

void TravPreIter(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	stack<TreeNode *>s;
	s.push(pRoot);
	while (!s.empty())
	{
		TreeNode *temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if (temp->rc != NULL)
			s.push(temp->rc);
		if (temp->lc != NULL)
			s.push(temp->lc);
	}
}

void TravPreIter1(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	stack<TreeNode *>s;
	TreeNode *currNode = pRoot;
	while (true)
	{
		while (currNode != NULL)
		{
			cout << currNode->data << " ";
			s.push(currNode->rc);
			currNode = currNode->lc;
		}
		if (s.empty())
			break;
		currNode = s.top();
		s.pop();
	}
}

void TravInIter(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	stack<TreeNode *>s;
	TreeNode *currNode = pRoot;
	while (true)
	{
		while (currNode != NULL)
		{
			s.push(currNode);
			currNode = currNode->lc;
		}
		if (s.empty())
			break;
		currNode = s.top();
		s.pop();
		cout << currNode->data << " ";
		currNode = currNode->rc;
	}
}

void TravPostIter(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	stack<TreeNode *>s;
	TreeNode *currNode = pRoot;
	TreeNode *previsited = NULL;
	while (currNode != NULL||!s.empty())
	{
		while (currNode != NULL)
		{
			s.push(currNode);
			currNode = currNode->lc;
		}
		currNode = s.top();
		if (currNode->rc == NULL || currNode->rc == previsited)
		{
			cout << currNode->data << " ";
			previsited = currNode;
			s.pop();
			currNode = NULL;
		}
		else
			currNode = currNode->rc;
	}
}

void TravLevel(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	queue<TreeNode *>q;
	q.push(pRoot);
	while (!q.empty())
	{
		TreeNode *currNode = q.front();
		q.pop();
		cout << currNode->data << " ";
		if (currNode->lc != NULL)
			q.push(currNode->lc);
		if (currNode->rc != NULL)
			q.push(currNode->rc);
	}
}

int DepthTree(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return 0;
	int depthLeft = DepthTree(pRoot->lc);
	int depthRight = DepthTree(pRoot->rc);
	return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
}

int CountNode(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return 0;
	return 1 + CountNode(pRoot->lc) + CountNode(pRoot->rc);
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

int main(int argc, char **argv)
{
	vector<int>vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	TreeNode *pRoot = CreateTree(vec);
	cout << "递归前序遍历:";
	TravPreRecu(pRoot);
	cout << endl;
	cout << "递归中序遍历:";
	TravInRecu(pRoot);
	cout << endl;
	cout << "递归后序遍历:";
	TravPostRecu(pRoot);
	cout << endl;
	cout << "非递归前序遍历:";
	TravPreIter1(pRoot);
	cout << endl;
	cout << "非递归中序遍历:";
	TravInIter(pRoot);
	cout << endl;
	cout << "非递归后序遍历:";
	TravPostIter(pRoot);
	cout << endl;
	cout << "层次遍历:";
	TravLevel(pRoot);
	cout << endl;
	cout << "树的深度:";
	int depthTree = DepthTree(pRoot);
	cout << depthTree<<endl;
	cout << "结点个数:";
	int countNode = CountNode(pRoot);
	cout << countNode << endl;

	Destory(pRoot);
	system("pause");
	return 0;
}