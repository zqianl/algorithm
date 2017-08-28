#include<iostream>
#include<sstream>

using namespace std;

int MoreThanHalfNum(int *data, int length)
{
	if (data == NULL||length <= 0)
		return 0;
	int result = data[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = data[i];
			times = 1;
		}
		else if (data[i] == result)
			++times;
		else
			--times;
	}
	
	times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (data[i] == result)
			++times;
	}
	if (times * 2 <= length)
		return 0;
	else
		return result;
}

void Test(const char *testName, int *data, int length, int expected)
{
	cout << testName << " starts: ";
	int num = MoreThanHalfNum(data, length);
	if (num == expected)
		cout << "passed" << endl;
	else
		cout << "failed" << endl;
}

void Test1()
{
	int data[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test("Test1", data, sizeof(data) / sizeof(int), 2);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}