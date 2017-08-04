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
	return result; //��������ʱ��Ҫ��֤���Ǿֲ�������Ҫ���ں����Ĳ����У������������÷�ʽ��ָ�뷽ʽ���ڵģ���Ҫ�����صĲ���
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