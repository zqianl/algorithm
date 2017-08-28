#include "48.h"


void Test(const char *testName, ListNode *pHead1,ListNode *pHead2,ListNode *expected)
{
	cout << testName << " starts: ";
	Solution s;
	if (s.FindFistCommonNode(pHead1, pHead2) == expected)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

void Test1()
{
	vector<ListNode *>vecListNode;
	vector<int>data = { 1, 2, 3, 4, 5, 6, 7};
	for (unsigned int i = 0; i < data.size(); ++i)
		vecListNode.push_back(new ListNode(data[i]));
	ListNode *pHead1=vecListNode[0];
	ListNode *pHead2=vecListNode[3];
	vecListNode[0]->pNext = vecListNode[1];
	vecListNode[1]->pNext = vecListNode[2];
	vecListNode[2]->pNext = vecListNode[5];
	vecListNode[5]->pNext = vecListNode[6];
	vecListNode[3]->pNext = vecListNode[4];
	vecListNode[4]->pNext = vecListNode[5];
	Test("Test1", pHead1, pHead2,vecListNode[5]);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}