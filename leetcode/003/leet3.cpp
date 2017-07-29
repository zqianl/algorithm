#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include"solution3.h"

using namespace std;

bool flag = true;

int main(int argc, char* argv[])
{
	int m,n;
	vector<vector<int>>data;
	vector<int>midData;
	int element;
	cin >> m>>n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int target;
	cin >> target;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> element;
			midData.push_back(element);
		}
		data.push_back(midData);
		midData.clear();
	}
	cplusplus::Solution<int> s;
	flag = s.findNumber(data, target,m,n);
	if (flag)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;
	std::system("pause");
	return 0;
}
