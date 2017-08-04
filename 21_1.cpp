#include<iostream>
#include<stdlib.h>
#include<cassert>
#include<time.h>
using namespace std;
//http://www.cnblogs.com/xwdreamer/archive/2012/09/25/2701185.html
//求M2，M3，M5的最小值
int Min(int number1, int number2, int number3)
{
	int min = (number1<number2) ? number1 : number2;
	return (min<number3) ? min : number3;
}

//获取第k个丑数，假定1为第一个丑数
int getUglyNumber2(int index)
{
	//如果index<=0表明输入有误，直接返回0
	if (index <= 0)
		return 0;

	//定义丑数数组，用于记录排序的丑数
	int *pUglyNumbers = new int[index];
	//第一个丑数为1
	pUglyNumbers[0] = 1;
	//第一个丑数的坐标是0，下一个丑数的坐标从1开始
	int nextUglyIndex = 1;
	//定义三个指向丑数数组的指针，用它们来标识从数组中的哪一个数开始计算M2，M3和M5，开始都是丑数数组的首地址。
	int *T2 = pUglyNumbers;
	int *T3 = pUglyNumbers;
	int *T5 = pUglyNumbers;

	while (nextUglyIndex<index)//
	{
		int min = Min(*T2 * 2, *T3 * 3, *T5 * 5);//M2=*T2 * 2, M3=*T3 * 3, M5=*T5 * 5
		pUglyNumbers[nextUglyIndex] = min;//求M2，M3，M5的最小值作为新的丑数放入丑数数组
		//每次生成新的丑数的时候，去更新T2，T3和T5.
		while (*T2 * 2 <= pUglyNumbers[nextUglyIndex])
			++T2;
		while (*T3 * 3 <= pUglyNumbers[nextUglyIndex])
			++T3;
		while (*T5 * 5 <= pUglyNumbers[nextUglyIndex])
			++T5;
		nextUglyIndex++;
	}
	int ugly = pUglyNumbers[index - 1];//因为丑数有序排列，所以丑数数组中的最后一个丑数就是我们所求的第index个丑数。
	delete[] pUglyNumbers;
	return ugly;
}

int main()
{
	int k = 1500;
	clock_t start, end;//用于统计程序运行时间
	start = clock();
	cout << getUglyNumber2(k) << endl;
	end = clock();
	cout << "Run time: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;//要记录分钟的话，上面的程序改为(double)(end - start) / CLOCKS_PER_SEC/60即可;

	system("pause");
	return 0;
}