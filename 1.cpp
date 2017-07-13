#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

int main()
{
	int num, sum;
	int element;
	int a = -1, b = -1;
	vector<int> data;
	cin >> num >> sum;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (num <= 1)
		cout << a << " " << b << endl;
	else
	{
		for (int i = 0; i != num; i++)
		{
			cin >> element;
			data.push_back(element);
		}
		auto i = data.begin();
		auto j = data.end()-1;
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
				cout << a << " " << b << endl;
				break;
			}
		}
	}
	std::system("pause");
	return 0;
}