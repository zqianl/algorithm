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
//判断是否循环，那还不简单，就像咱们跑圈一样呗，再次经过起点不就证明是环？如果一直跑，跑到头都没见到起点，是不是就不是环？
//现在@pezy 和 @Mooophy 一起跑步， pezy慢，Mooophy跑的嗖嗖的。只要存在环，那么飞快的 Mooophy一定可以套 pezy的圈。如果不存
//在环， pezy 望着 Mooophy绝尘而去，将再也无法赶上他的脚步。
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