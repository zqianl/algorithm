#include<iostream>
#include<sstream>

using namespace std;

int Random(int start, int end)
{
	int index = rand() % (end - start + 1) + start;
	return index;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int *data, int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		return 0;
	int index = Random(start, end);
	Swap(data[index], data[end]);

	int small = start - 1;
	for (int i = start; i < end; ++i)
	{
		if (data[i] < data[end])
		{
			++small;
			if (i != small)
				Swap(data[i], data[small]);
		}
	}
	++small;
	Swap(data[small], data[end]);
	return small;
}

int MoreThanHalfNum(int *data, int length)
{
	if (data == NULL || length <= 0)
		return 0;
	int result;
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;

	int index = Partition(data, length, start, end);

	while (index != middle)
	{
		if (index < middle)
		{
			start = index + 1;
			index = Partition(data, length, start, end);
		}
		else
		{
			end = index - 1;
			index = Partition(data, length, start, end);
		}
	}

	result = data[index];
	int times = 0;
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