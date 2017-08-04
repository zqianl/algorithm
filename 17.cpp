#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>
#include<stdio.h>

using namespace std;

int& FindSingleNum(const vector<int> & vec,int &result)
{
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		result = result ^ (*i);
	}
	return result; //返回引用时需要保证不是局部变量，要求在函数的参数中，包含有以引用方式或指针方式存在的，需要被返回的参数
}

int main(int argc, char*argv[])
{
	int m;
	vector<int>data;
	while (cin >> m)
		data.push_back(m);
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	int a = 0;
	int result = FindSingleNum(data,a);
	cout << result << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout.precision(6);
	cout << time_used.count() << endl;
	system("pause");
	return 0;
}