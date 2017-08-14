#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

void isFind(int &num, int &sum, const vector<int> &data, int &a, int &b)
{
	vector<int>hashBool(sum,0);
	auto mid = data.begin();
	auto midHashBool = hashBool.begin();
	for (int i = 0; i < num; i++)
	{
		if (*(mid + i) > sum)
			continue;
		else
		{
			if (*(midHashBool+*(mid+i))==0)
				*(midHashBool + sum-*(mid + i)) = 1;
			else
			{
				a = *(mid + i);
				b = sum - *(mid + i);
				cout << a << " " << b << endl;
				return;
			}
		}
	}
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