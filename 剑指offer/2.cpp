#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

bool isFind(const vector<vector<int>> &matrix, int &m, int &n, int &key, int &a, int&b)
{
	int row = 1, col = n;
	while (row <=m && col >= 1)
	{
		if (matrix[row - 1][col - 1] > key)
			col--;
		else if (matrix[row - 1][col - 1] < key)
			row++;
		else
		{
			a = row;
			b = col;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int m, n;
	int key;
	cin >> m >> n>>key;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (m >= 1 && n >= 1)
	{
		vector<vector<int>>matrix;
		vector<int>data;
		int number;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> number;
				data.push_back(number);
			}
			matrix.push_back(data);
			data.clear();
		}
		int a, b;
		bool flag = isFind(matrix, m, n, key,a,b);
		if (flag)
			cout << key << " is in " << a << "行" << b << "列" << endl;
		else
			cout << "Not Find!" << endl;
	}
	else
		cout << "输入有误" << endl;
	return 0;
}