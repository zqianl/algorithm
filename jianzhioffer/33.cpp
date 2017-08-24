#include "33.h"

int main(int argc, char **argv)
{
	//第一种建立链表的方法
	//ListNode *pNode1 = new ListNode(1);
	//ListNode *pNode2 = new ListNode(2);
	//ListNode *pNode3 = new ListNode(3);
	//ListNode *pNode4 = new ListNode(4);
	//ListNode *pNode5 = new ListNode(5);

	//pNode1->next = pNode2;
	//pNode2->next = pNode3;
	//pNode3->next = pNode4;
	//pNode4->next = pNode5;

	//Solution s;
	//s.DeleteNode(&pNode1, pNode1);


	//第二种建立链表的方法
	int number[5] = {1,2,3,4,5};
	vector<ListNode *>vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(new ListNode(number[i]));
	for (auto i = 0; i < vec.size()-1; ++i)
	{
		vec[i]->next = vec[i + 1];
	}
	Solution s;
	s.DeleteNode(&vec[0], vec[4]);

	if (vec[0] != NULL)
	{
		ListNode *pNode = vec[0];
		while (pNode != NULL)
		{
			cout << pNode->data << endl;
			pNode = pNode->next;
		}
	}

	ListNode *pNode = vec[0];
	ListNode *pNodeNext = NULL;
	while (pNode != NULL)
	{
		pNodeNext = pNode->next;
		delete pNode;
		pNode = pNodeNext;
	}
	system("pause");
	return 0;
}