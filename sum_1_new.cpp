#include<iostream>
#include<vector>
#include<numeric>
#include<limits>
#include<array>

using namespace std;

void isFind(int &num, int &sum, const vector<int> &data, int &a, int &b)
{
	int *p = new int[sum]();
	auto mid = data.begin();
	for (int i = 0; i < num; i++)
	{
		if (*(mid + i) > sum)
			continue;
		else
		{
			if (p[*(mid + i)] == 0)
			{
				p[sum-*(mid + i)] = 1;
			}
			else
			{
				a = *(mid + i);
				b = sum - *(mid + i);
				cout << a << " " << b << endl;
				delete[] p;
				return;
			}
		}
	}
	delete[] p;
	cout << "Not Find!" << endl;
}

int main()
{
	int num, sum;
	vector<int>data;
	cin >> num >> sum;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (num <= 1)
	{
		cout << -1 << " " << -1 << endl;
	}
	else
	{
		int i = 0;
		int number;
		while (i < num)
		{
			cin >> number;
			data.push_back(number);
			i++;
		}
	}
	int a, b;
	isFind(num, sum, data, a, b);
	std::system("pause");
	return 0;
}