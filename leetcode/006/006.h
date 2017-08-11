#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL){}
};
//�ж��Ƿ�ѭ�����ǻ����򵥣�����������Ȧһ���£��ٴξ�����㲻��֤���ǻ������һֱ�ܣ��ܵ�ͷ��û������㣬�ǲ��ǾͲ��ǻ���
//����@pezy �� @Mooophy һ���ܲ��� pezy����Mooophy�ܵ��ವġ�ֻҪ���ڻ�����ô�ɿ�� Mooophyһ�������� pezy��Ȧ���������
//�ڻ��� pezy ���� Mooophy������ȥ������Ҳ�޷��������ĽŲ���
class Solution{
public:
	bool hasCycle(ListNode * head)
	{
		if (head&&head->next)
		{
			for (ListNode *slower = head, *faster = head->next; faster && faster->next; slower = slower->next, faster = faster->next->next)
			{
				if (slower == faster)
					return true;
			}
		}
		return false;
	}
};


#endif