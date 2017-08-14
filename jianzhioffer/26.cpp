#include"26.h"

//²âÊÔÊäÈë£º
//8
//1 2 4 7 3 5 6 8
//4 7 2 1 5 3 8 6
int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int>pre;
	vector<int>inv;
	int element;
	for (int i = 0; i != num; ++i)
	{
		cin >> element;
		pre.push_back(element);
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i != num; ++i)
	{
		cin >> element;
		inv.push_back(element);
	}
	Solution s;
	bool canRebuildOrNot = s.RebuildTree(pre, inv);
	if (canRebuildOrNot)
	{
		s.behTraverse(s.root);
		s.destory(s.root);
	}
	else
		cout << "NO!" << endl;
	system("pause");
	return 0;
}