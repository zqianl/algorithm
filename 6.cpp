#include<iostream>
#include<ctime>
#include<chrono>
using namespace std;

long long Fibonacci(unsigned int i)
{
	long long ret;
	long long a = 0;
	long long b = 1;
	long long c;
	if (i == 1)
		ret = 0;
	else if (i == 2)
		ret = 1;
	else
	{
		for (unsigned int j = 2; j < i; j++)
		{
			c = b;
			b = b + a;
			a = c;
		}
		ret = b;
	}
	return ret;
}

//ËÙ¶ÈºÜÂý
//long long Fibonacci(unsigned int i)
//{
//	if (i == 1)
//		return 0;
//	if (i == 2)
//		return 1;
//	return Fibonacci(i - 1) + Fibonacci(i - 2);
//}

int main()
{
	unsigned int i;
	cin >> i;
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	cout << Fibonacci(i) << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float> time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout  << time_used.count() << endl;
	std::system("pause");
	return 0;
}