#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

int calNum_1(int &element)
{
	int num_1=0;
	while (element != 0)
	{
		element = element&(element - 1);
		num_1++;
	}
	return num_1;
}

int main()
{
	int num;
	int element;
	vector<int>data;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; i++)
	{
		cin >> element;
		data.push_back(element);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	for (int j = 0; j < num; j++)
	{
		int num_1 = calNum_1(*(data.begin()+j));
		cout << num_1 << endl;
	}
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float> time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << "¼ÆËãÓÃÊ±: " << time_used.count() << endl;
	std::system("pause");
	return 0;
}