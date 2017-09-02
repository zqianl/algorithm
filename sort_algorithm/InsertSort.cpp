#include<iostream>

using namespace std;

void InsertSort(int data[], int length)
{
	int i, j, k;
	for (i = 1; i < length; ++i)
	{
		for (j = i - 1; j >= 0; --j)
		{
			if (data[j] < data[i])
				break;
		}
		if (j != i - 1)
		{
			int temp = data[i];
			for (k = i - 1; k > j; --k)
			{
				data[k + 1] = data[k];
			}
			data[k + 1] = temp;
		}
	}
}

void InsertSort1(int data[], int length)
{
	int i, j;
	for (i = 1; i < length; ++i)
	{
		if (data[i] < data[i - 1])
		{
			int temp = data[i];
			for (j = i - 1; j >= 0 && data[j] > temp; j--)
				data[j + 1] = data[j];
			data[j + 1] = temp;
		}
	}
}

int main()
{
	int data[] = { 3, 2, 5, 6, 4, 1, 9, 7, 8, 0 };
	int n = sizeof(data) / sizeof(int);
	InsertSort(data, n);
	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";
	system("pause");
	return 0;
}