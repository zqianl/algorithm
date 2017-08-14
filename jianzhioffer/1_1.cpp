#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

void isFind(int &num, int &sum, const vector<int>& data, int &a, int &b)
{
	auto i = data.begin();
	auto j = data.end() - 1;
	while (i < j)
	{
		if (*i + *j < sum)
			i++;
		else if (*i + *j > sum)
			j--;
		else
		{
			a = *i;
			b = *j;
			return;
		}
	}
	a = -1;
	b = -1;
}

int main()
{
	int num, sum;
	vector<int> data;
	int number;
	cin >> num >> sum;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (num <= 1)
	{
		cout << -1 << " " << -1 << endl;
	}
	else
	{
		int i = 0;
		while (i < num)
		{
			cin >> number;
			data.push_back(number);
			i++;
		}
	}
	int a=-1, b=-1;
	isFind(num, sum, data, a, b);
	cout << a << " " << b << endl;
	std::system("pause");
	return 0;
}
