#include "43.h"

void BuildComplexList(ComplexListNode *pListHead, ComplexListNode *next, ComplexListNode *pSibling)
{
	if (pListHead == NULL)
		return;
	pListHead->next = next;
	pListHead->pSibling = pSibling;
}

void PrintComplexList(ComplexListNode *pListNode)
{
	ComplexListNode *pNode = pListNode;
	while (pNode != NULL)
	{
		cout << "the value of the current ListNode is: " << pNode->data << endl;
		if (pNode->next != NULL)
			cout << "The value of the next ListNode is " << pNode->next->data << endl;
		if (pNode->pSibling != NULL)
			cout << "the value of the pSibling is " << pNode->pSibling->data << endl;
		pNode = pNode->next;
	}
}

void Destory(ComplexListNode *pListHead)
{
	ComplexListNode *next = NULL;
	ComplexListNode *curr = pListHead;
	while (curr != NULL)
	{
		next = curr->next;
		delete curr;
		curr = NULL;
		curr = next;
	}
}

void Test(const char *testName,ComplexListNode *pListHead)
{
	cout << testName << " starts: " << endl;
	cout << "the original List is:" << endl;
	PrintComplexList(pListHead);

	Solution s;
	ComplexListNode *pCloneListHead=s.CopyComplexList(pListHead);

	cout << "the clone List is: " << endl;
	PrintComplexList(pCloneListHead);

	Destory(pListHead);
	Destory(pCloneListHead);
}

void Test1()
{
	vector<int> data = {1, 2, 3, 4, 5};
	vector<ComplexListNode *>vec;
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		vec.push_back(new ComplexListNode(data[i]));
	}
	//          -----------------
	//         \|/              |
	//  1-------2-------3-------4-------5
	//  |       |      /|\             /|\
	//  --------+--------               |
	//          -------------------------
	BuildComplexList(vec[0], vec[1], vec[2]);
	BuildComplexList(vec[1], vec[2], vec[4]);
	BuildComplexList(vec[2], vec[3], NULL);
	BuildComplexList(vec[3], vec[4], vec[1]);
	Test("Test1", vec[0]);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}