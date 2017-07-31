#include<iostream>
#include<vector>
#include<numeric>
#include<limits>
#include"10solution.h"

using namespace std;

int main(int agrc, char*agrv[])
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<char>data(num, '0');
	cplusplus::Solution<char> s;
	s.printToNum(data);
	system("pause");
	return 0;
}