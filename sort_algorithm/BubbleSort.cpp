#include<iostream>
#include<vector>

using namespace std;

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort1(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n - i - 1; ++j)
		{
			if (a[j]>a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}
}

void BubbleSort2(int *a, int n)
{
	int i, j = n;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (i = 0; i < j - 1; ++i)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = true;
			}
		}
		--j;
	}
}

void BubbleSort3(int *a, int n)
{
	int i, j;
	int flag = n;
	while (flag > 0)
	{
		j = flag;
		flag = 0;
		for (i = 0; i < j - 1; ++i)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = i + 1;
			}
		}
	}

}

int main(int argc, char **argv)
{
	int a[10] = { 8, 3, 5, 2, 7, 6, 1, 9, 4, 0 };
	BubbleSort1(a, 10);
	int b[10] = { 8, 3, 5, 2, 7, 6, 1, 9, 4, 0 };
	BubbleSort2(b, 10);
	int c[10] = { 8, 3, 5, 2, 7, 6, 1, 9, 4, 0 };
	BubbleSort3(c, 10);
	for (int i = 0; i < 10; ++i)
		cout << a[i]<<" ";
	cout << endl;
	for (int i = 0; i < 10; ++i)
		cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; ++i)
		cout << c[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}