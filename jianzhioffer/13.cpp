#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;
//迭代，常规不符合该题要求
int cumSum(int num)
{
	if (num == 1)
		return 1;
	else
		return cumSum(num - 1)+num;
}
// ====================方法一====================
class Solution{
public:
	Solution(){ ++N; Sum += N; }
	int GetSum(){ return Sum; }
private:
	static int N;
	static int Sum;
};

int Solution::N = 0;
int Solution::Sum = 0;

int cumSum1(int n)
{
	Solution *s = new Solution[n];
	int result = (*s).GetSum();
	delete[] s;
	s = NULL;
	return result;
}
// ====================方法二====================
typedef int(*fun)(int n);
int Teminator(int n)
{
	return 0;
}
int cumSum2(int n)
{
	fun f[2] = { Teminator, cumSum2 };
	return n + f[!!n](n - 1);
}
// ====================方法三====================
class A;
A *Array[2];
class A{
public:
	virtual int Sum(int n)
	{
		return 0;
	}
};
class B :public A{
public:
	virtual int Sum(int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};
int cumSum3(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}

int main(int argc, char*argv[])
{
	int m;
	vector<int>data;
	while (cin >> m)
	{
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		data.push_back(m);
	}
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		int result = cumSum3(*i);
		cout << result << endl;
	}
	system("pause");
	return 0;

}