#include<iostream>
#include<stdlib.h>
#include<cassert>
#include<time.h>
using namespace std;
//http://www.cnblogs.com/xwdreamer/archive/2012/09/25/2701185.html
//��M2��M3��M5����Сֵ
int Min(int number1, int number2, int number3)
{
	int min = (number1<number2) ? number1 : number2;
	return (min<number3) ? min : number3;
}

//��ȡ��k���������ٶ�1Ϊ��һ������
int getUglyNumber2(int index)
{
	//���index<=0������������ֱ�ӷ���0
	if (index <= 0)
		return 0;

	//����������飬���ڼ�¼����ĳ���
	int *pUglyNumbers = new int[index];
	//��һ������Ϊ1
	pUglyNumbers[0] = 1;
	//��һ��������������0����һ�������������1��ʼ
	int nextUglyIndex = 1;
	//��������ָ����������ָ�룬����������ʶ�������е���һ������ʼ����M2��M3��M5����ʼ���ǳ���������׵�ַ��
	int *T2 = pUglyNumbers;
	int *T3 = pUglyNumbers;
	int *T5 = pUglyNumbers;

	while (nextUglyIndex<index)//
	{
		int min = Min(*T2 * 2, *T3 * 3, *T5 * 5);//M2=*T2 * 2, M3=*T3 * 3, M5=*T5 * 5
		pUglyNumbers[nextUglyIndex] = min;//��M2��M3��M5����Сֵ��Ϊ�µĳ��������������
		//ÿ�������µĳ�����ʱ��ȥ����T2��T3��T5.
		while (*T2 * 2 <= pUglyNumbers[nextUglyIndex])
			++T2;
		while (*T3 * 3 <= pUglyNumbers[nextUglyIndex])
			++T3;
		while (*T5 * 5 <= pUglyNumbers[nextUglyIndex])
			++T5;
		nextUglyIndex++;
	}
	int ugly = pUglyNumbers[index - 1];//��Ϊ�����������У����Գ��������е����һ������������������ĵ�index��������
	delete[] pUglyNumbers;
	return ugly;
}

int main()
{
	int k = 1500;
	clock_t start, end;//����ͳ�Ƴ�������ʱ��
	start = clock();
	cout << getUglyNumber2(k) << endl;
	end = clock();
	cout << "Run time: " << (double)(end - start) / CLOCKS_PER_SEC << "S" << endl;//Ҫ��¼���ӵĻ�������ĳ����Ϊ(double)(end - start) / CLOCKS_PER_SEC/60����;

	system("pause");
	return 0;
}