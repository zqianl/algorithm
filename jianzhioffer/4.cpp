#include<iostream>
#include<map>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

int main()
{
	int age;
	int len;
	map<int, int>ages;
	cin >> len;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < len; i++)
	{
		cin >> age;
		++ages[age];
	}
	//����pair�󣬰��չؼ����Ѿ����򣬰�˳���ӡ����
	for (pair<const int,int> &w : ages)
	{
		while (w.second)
		{
			cout << w.first << " ";
			w.second--;
		}
	}
	return 0;
}