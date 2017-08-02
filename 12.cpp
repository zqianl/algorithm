#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

int sumNoAdd(const vector<int>& vec)
{
	int result = *vec.begin() ^ *(vec.begin() + 1);
	int add = (*vec.begin() & *(vec.begin() + 1))<<1;//add表示进位
	while (add != 0)
	{
		int mid = result;
		result = result^add;
		add = (mid&add) << 1;
	}
	return result;
}

int main(int argc, char*argv[])
{
	int m, n;
	vector<int>element;
	vector<vector<int>>data;
	while (cin >> m >> n)
	{
		element.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		element.push_back(m);
		element.push_back(n);
		data.push_back(element);
	}
	for (auto i=data.begin(); i < data.end(); ++i)
	{
		int result = sumNoAdd(*i);
		cout << result << endl;
	}
	system("pause");
	return 0;

}