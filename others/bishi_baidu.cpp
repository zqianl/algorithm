//2018�ٶȱ��� 
//1��Ѱ��˫����
//һ����Ϊ�������ҽ��䰴��ʮ���Ʒ�����֮�󲻵�����������ȻΪ����������������Ϊ˫����
//Ѱ�ҵ�k��˫������k<10000��������ս������1000000�����-1
#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

bool IsPrime(const int number)
{
	bool flag = true;
	int sqrtNum = sqrt(number);
	for (int i = 2; i <= sqrtNum; ++i)
	{
		if (number%i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int ReverseNum(int number)
{
	vector<int>vecNum;
	while (number != 0)
	{
		int remain = number % 10;
		vecNum.push_back(remain);
		number /= 10;
	}
	int sum = 0;
	for (int i = 0; i < vecNum.size(); ++i)
	{
		sum += vecNum[i] * pow(10, vecNum.size() - 1 - i);
	}
	return sum;
}

bool IsDoublePrime(int number)
{
	bool flagIsPrime = IsPrime(number);
	if (flagIsPrime == true)
	{
		int numberRev = ReverseNum(number);
		if (numberRev == number)
			flagIsPrime = false;
		else
			flagIsPrime = IsPrime(numberRev);
	}
	return flagIsPrime;
}

int main(int argc, char **argv)
{
	int k;
	cin >> k;
	int count=0;
	int i = 12;
	for (; i <= 1000000; ++i)
	{
		bool flag = IsDoublePrime(i);
		if (flag == true)
			count++;
		if (count == k)
			break;
	}
	if (count == k)
		cout << i << endl;
	else
		cout << "-1" << endl;
	return 0;
}


//2������f��n��=a7*n^7+a6*n^6+...+a0,����k�飨a7...a0������k��ֵ�ֱ����n=1��2...
//Ѱ�ҵ�kС��ֵΪ����
#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

long long CalFunc(vector<int>midData, int base)
{
	long long sum = 0;
	for (int i = 0; i < 8; ++i)
	{
		sum += midData[i] * pow(base, 7 - i);
	}
	return sum;
}

long long CalMin(vector<long long>setNum, int &m)
{
	long long minValue = *setNum.begin();
	int min = 0;
	int count = 0;
	for (auto i = setNum.begin() + 1; i != setNum.end(); ++i)
	{
		count++;
		if (*i < minValue)
		{
			min = count;
			minValue = *i;
		}
	}
	m = min;
	return minValue;
}

int main(int argc, char **argv)
{
	int k;
	cin >> k;
	vector<vector<int>>vecNum;
	vector<int>midNum;
	int data;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> data;
			midNum.push_back(data);
		}
		vecNum.push_back(midNum);
		midNum.clear();
	}
	int n;
	cin >> n;
	vector<int>sequ(k, 1);
	vector<long long>setNum;
	for (int i = 0; i < k; ++i)
	{
		long long f = CalFunc(vecNum[i], sequ[i]);
		setNum.push_back(f);
	}
	int count = 0;
	long long result = 0;
	while (count != n)
	{
		int m;
		result = CalMin(setNum, m);
		sequ[m]++;
		long long f = CalFunc(vecNum[m], sequ[m]);
		setNum[m] = f;
	}
	cout << result << endl;
	return 0;
}


