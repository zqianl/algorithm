#include<iostream>
#include<vector>
#include"solution2.h"

using namespace std;

int main(int agrc, char*agrv[])
{
	vector<int>data{ 9, 9, 9, 9 };
	vector<int>result;
	cplusplus::Solution<int> s;
	result = s.plusOne(data);
	for (auto i = result.begin(); i != result.end(); i++)
		cout << *i;
	cout << endl;
	return 0;
}