#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

int cumSum(int num)
{
	if (num == 1)
		return 1;
	else
		return cumSum(num - 1)+num;
}

int main(int argc, char*argv[])
{
	int m;
	vector<int>data;
	while (cin >> m)
	{
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		data.push_back(m);
	}
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		int result = cumSum(*i);
		cout << result << endl;
	}
	system("pause");
	return 0;

}