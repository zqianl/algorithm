#include<iostream>
#include<vector>
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
			++ small;
			if (i != small)
				Swap(data[i], data[small]);
		}
	}
	++small;
	Swap(data[small], data[end]);
	return small;
}

vector<int> MinNumData(int *data, int length,int minNum)
{
	if (data == NULL || length <= 0 || minNum <= 0)
		throw new std::exception("Invalid Parameters");
	int start = 0;
	int end = length - 1;
	int index = Partition(data, length, start, end);
	while (index != minNum)
	{
		if (index < minNum)
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
	vector<int>result;
	for (int i = 0; i < minNum;++i)
		result.push_back(data[i]);
	return result;
}

void Test(const char *testName, int *data, int length, int minNum)
{
	cout << testName << " starts: ";
	vector<int>vec;
	vec = MinNumData(data, length,minNum);
	for (auto &i : vec)
		cout << i << " ";
	cout << endl;
}

void Test1()
{
	int minNum = 4;
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("Test1", data, sizeof(data) / sizeof(int), minNum);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}