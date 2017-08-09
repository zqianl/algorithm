#include<iostream>
#include<algorithm>
#include"22_1.h"

using namespace std;

int main()
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	bintree::TreeNode<int> *root = new bintree::TreeNode<int>[num];
	if (root == NULL)
		exit(EXIT_FAILURE);
	int m, n;
	for (int i = 0; i < num; ++i)
	{
		cin >> m >> n;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (m != -1)
			root[i].lc = m - 1;
		else
			root[i].lc = -1;
		if (n != -1)
			root[i].rc = n - 1;
		else
			root[i].rc = -1;
	}
	bintree::Solution<int> s;
	cout << "The depth is: ";
	cout << s.calMaxDepth(root,0) << endl;
	system("pause");
	return 0;
}
