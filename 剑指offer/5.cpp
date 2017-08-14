#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

int main()
{
	int num;
	int element;
	int answer;
	vector<int> data;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; i++)
	{
		cin >> element;
		if (num == 1)
		{
			answer = element;
			cout << "the min number is: " << answer << endl;
			return 0;
		}
		else
			data.push_back(element);
	}
	vector<int>::iterator itBegin = data.begin();
	vector<int>::iterator itEnd = data.end()-1;
	if (num > 2)
	{
		if (*itBegin < *itEnd)
		{
			answer = *itBegin;
			cout << "the min number is: " << answer << endl;
			return 0;
		}
		else
		{
			vector<int>::iterator itMid = itBegin + (itEnd - itBegin) / 2;
			while ((itEnd - itBegin) >= 2)
			{
				if (*itMid > *itBegin)
					itBegin = itMid;
				else
					itEnd = itMid;
				if ((itEnd - itBegin) >= 2)
					itMid = itBegin + (itEnd - itBegin) / 2;
			}
		}
	}
	if (*itEnd > *itBegin)
		answer = *itBegin;
	else
		answer = *itEnd;
	cout << "the min number is: " << answer << endl;
	std::system("pause");
	return 0;
}