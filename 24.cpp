#include "24.h"

int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (num == 0)
		cout << "NULL" << endl;
	else
	{
		int element;
		vector<ListNode *>vec;
		for (int i = 0; i != num; ++i)
		{
			cin >> element;
			vec.push_back(new ListNode(element));
		}
		for (decltype(vec.size())i = 0; i != vec.size() - 1; ++i)
		{
			vec[i]->next = vec[i + 1];
		}
		vec[vec.size() - 1]->next = NULL;

		Solution s;
		ListNode *revHead;
		revHead=s.reverseList1(vec[0]);
		while (revHead != NULL)
		{
			cout << revHead->val << " ";
			revHead = revHead->next;
		}
	}
	return 0;
}