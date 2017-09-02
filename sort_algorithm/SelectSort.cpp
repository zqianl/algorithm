#include<iostream>

using namespace std;

void Swap(int &a, int &b)
{
	if (a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}

void SelectSort(int data[], int length)
{
	int i, j, minIndex;
	for (i = 0; i < length; ++i)
	{
		minIndex = i;
		for (j = i + 1; j < length; ++j)
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		Swap(data[i], data[minIndex]);
	}
}

int main()
{
	int data[] = { 3, 2, 5, 6, 4, 1, 9, 7, 8, 0 };
	int n = sizeof(data) / sizeof(int);
	SelectSort(data, n);
	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";
	system("pause");
	return 0;
}