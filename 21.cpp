#include<iostream>
#include<stdlib.h>
#include<cassert>
#include<time.h>
using namespace std;

//http://www.cnblogs.com/xwdreamer/archive/2012/09/25/2701185.html

//判断是否为丑数
bool isUgly(int number)
{
	while (number % 2 == 0)
		number = number / 2;
	while (number % 3 == 0)
		number = number / 3;
	while (number % 5 == 0)
		number = number / 5;
	return (number == 1) ? true : false;
}

//获取第k个丑数，假定1为第一个丑数
int getUglyNumber(int index)
{
	int number = 0;
	int count = 0;
	while (count<index)
	{
		++number;
		if (isUgly(number))
			count++;
	}
	return number;
}

int main()
{
	int k = 1500;
	clock_t start, end;//用于统计程序运行时间
	start = clock();
	cout << getUglyNumber(k) << endl;
	end = clock();
	cout << "Run time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;//要记录分钟的话，上面的程序改为(double)(end - start) / CLOCKS_PER_SEC/60即可;
	system("pause");
	return 0;
}