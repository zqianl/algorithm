#include "32.h"

void CreateBST(BSTNode **pRoot)
{
	int data;
	cin >> data;
	if (data == 0)
		pRoot = NULL;
	else
	{
		*pRoot = new BSTNode(data);
		CreateBST(&((*pRoot)->lc));
		CreateBST(&((*pRoot)->rc));
	}
}

int main(int argc, char **argv)
{
	BSTNode* pRoot = NULL;
	CreateBST(&pRoot);
	Solution s;
	BSTNode *pHead = s.Convert(pRoot);
	while (pHead != NULL)
	{
		cout << pHead->data << " ";
		pHead = pHead->rc;
	}
	system("pause");
	return 0;
}