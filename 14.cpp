#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

bool flag = true;

int FindLast(const vector<int>& vec)
{
	auto m = vec.begin(), n = vec.begin() + 1;
	if (*m < 1 || *n < 1)
	{
		flag = false;
		return 0;
	}
	else
	{
		int result = 0;
		if (*m >= 2)
			for (int i = 2; i <= *m; ++i)
				result = (result + *n) % i;
		return result;
	}
}

int main(int argc, char*argv[])
{
	int m, n;//m表示人数，n表示指定的数
	vector<int>element;
	vector<vector<int>>data;
	while (1)
	{
		cin >> m;
		if (m != 0)
		{
			cin >> n;
			element.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			element.push_back(m);
			element.push_back(n);
			data.push_back(element);
		}
		else
			break;
	}
	cout << "output:" << endl;
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		bool flag = true;
		int result = FindLast(*i);
		if (flag)
			cout << result << endl;
		else
			cout << "Input Error!" << endl;
	}
	system("pause");
	return 0;

}