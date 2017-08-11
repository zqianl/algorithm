#include"006.h"

//############   与方法2对应   #####################
ListNode* createList(const vector<int> &data)
{
	vector<ListNode *>vec;
	for (auto i = data.begin(); i != data.end(); ++i)
	{
		vec.push_back(new ListNode(*i));
	}
	vec[0]->next = vec[1];
	vec[1]->next = vec[2];
	vec[2]->next = vec[3];
	vec[3]->next = vec[4];
	vec[4]->next = vec[5];
	vec[5]->next = vec[0];
	return *vec.begin();
}

//普通单链表的删除
//void destroyList(ListNode* node)
//{
//	if (node == NULL)
//		return;
//	ListNode *p = NULL;
//	while (node != NULL)
//	{
//		p = node->next;
//		delete node;
//		node = p;
//	}
//}

//循环链表的删除：头尾相接也简单
//void destroyList(ListNode* node)
//{
//	if (node == NULL)
//		return;
//	ListNode *p = node->next;
//	ListNode *q = NULL;
//	node->next = NULL;
//	while (p != NULL)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//}

//在某一个地方有环，则删除需要找到环连接的地方

//########################################################

int main()
{
	////// 建链表方式1
	//ListNode node1(1);
	//ListNode node2(2);
	//ListNode node3(3);
	//ListNode node4(4);
	//ListNode node5(5);
	//ListNode node6(6);

	//node1.next = &node2;
	//node2.next = &node3;
	//node3.next = &node4;
	//node4.next = &node5;
	//node5.next = &node6;
	//node6.next = &node1;

	//Solution s;
	//cout << s.hasCycle(&node1) << endl;

	//  建链表方式2
	vector<int>vec = { 1, 2, 3, 4, 5, 6 };
	ListNode *node1 = createList(vec);

	Solution s;
	cout << s.hasCycle(node1) << endl;
	//destroyList(node1);
	system("pause");
	return 0;
}
