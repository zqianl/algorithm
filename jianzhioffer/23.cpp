#include"23.h"

int main(int argc, char *argv[])
{
	int num;
	vector<ListNode *>vec;
	while (cin >> num)
	{
		if (num != -1)
		{
			vec.push_back(new ListNode(num));
		}
		else
			break;
	}
	if (vec.size() == 0)
		return 0;
	else
	{
		for (decltype(vec.size())i = 0; i != vec.size() - 1; ++i)
		{
			vec[i]->next = vec[i + 1];
		}
		vec[vec.size() - 1]->next = NULL;
	}
	Solution s;
	s.printList(vec[0]);

	ListNode *p = vec[0];
	ListNode *q = NULL;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	system("pause");
	return 0;
}