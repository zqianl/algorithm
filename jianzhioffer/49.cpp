#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int GetFirstK(int *data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middle = (start + end) / 2;
	if (data[middle] == k)
	{
		if ((middle > 0 && data[middle - 1] != k) || middle == 0)
			return middle;
		else
			end = middle - 1;
	}
	else if (data[middle] > k)
	{
		end = middle - 1;
	}
	else
	{
		start = middle + 1;
	}
	return GetFirstK(data, length, k, start, end);
}

int GetLastK(int *data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middle = (start + end) / 2;
	if (data[middle] == k)
	{
		if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1)
			return middle;
		else
			start = middle + 1;
	}
	else if (data[middle] < k)
	{
		start = middle + 1;
	}
	else
	{
		end = middle - 1;
	}
	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int *data, int length, int k)
{
	int number = 0;
	int firstK = GetFirstK(data, length, k, 0, length - 1);
	int lastK = GetLastK(data, length, k, 0, length - 1);
	if (firstK != -1 && lastK != -1)
	{
		number = lastK - firstK + 1;
	}
	return number;
}

void Test(const char *testName, int *data, int length,int k,int expected)
{
	cout << testName << " starts: ";
	if ( GetNumberOfK(data,length,k)== expected)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

void Test1()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	Test("Test1", data, 8, 3, 4);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}