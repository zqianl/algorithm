#include"25.h"

int main(int argc, char*argv[])
{
	int num, target;
	cin >> num >> target;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (num < 1)
	{
		cout << "NULL" << endl;
		return NULL;
	}
	else
	{
		int element;
		vector<ListNode *>vec;
		for (int i = 0; i < num; ++i)
		{
			cin >> element;
			vec.push_back(new ListNode(element));
		}
		for (decltype(vec.size())i = 0; i != vec.size()-1; ++i)
		{
			vec[i]->next = vec[i + 1];
		}
		vec[vec.size() - 1] -> next = NULL;
		if (target > num || target == 0)
		{
			cout << "NULL" << endl;
			return NULL;
		}
		else
		{
			Solution s;
			ListNode *targetNode = s.FindLastk(vec[0], target);
			cout << targetNode->val << endl;
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
	}
}