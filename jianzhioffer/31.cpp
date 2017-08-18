#include "31.h"

int main(int agrc, char *agrv[])
{
	int m, n;
	vector<ListNode *>vec1;
	vector<ListNode *>vec2;
	cin >> m >> n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (m == 0 && n == 0)
		cout << "NULL" << endl;
	else
	{
		int num;
		if (m != 0)
		{
			for (int i = 0; i < m; ++i)
			{
				cin >> num;
				vec1.push_back(new ListNode(num));
			}
			for (decltype(vec1.size())i = 0; i < vec1.size() - 1; ++i)
			{
				vec1[i]->next = vec1[i + 1];
			}
			vec1[vec1.size() - 1]->next = NULL;
		}
		if (n != 0)
		{
			for (int i = 0; i < n; ++i)
			{
				cin >> num;
				vec2.push_back(new ListNode(num));
			}
			for (decltype(vec2.size())i = 0; i < vec2.size() - 1; ++i)
			{
				vec2[i]->next = vec2[i + 1];
			}
			vec2[vec2.size() - 1]->next = NULL;
		}
	}
	Solution s;
	ListNode *mergeHead;
	if (m == 0)
		mergeHead = vec2[0];
	else if (n == 0)
		mergeHead = vec1[0];
	else
	{
		mergeHead = s.mergeList(vec1[0], vec2[0]);
	}
	s.printMergeList(mergeHead);
	s.destoryMergeList(mergeHead);
	system("pause");
	return 0;
}