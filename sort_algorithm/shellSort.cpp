#include<iostream>

using namespace std;

void ShellSort(int data[], int length)
{
	int i, j, gap;
	for (gap = length / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; ++i)
		{
			for (j = i + gap; j < length; j += gap)
			{
				if (data[j]<data[j - gap])
				{
					int temp = data[j];
					int k = j - gap;
					for (; k >= 0 && data[k] > temp; k -= gap)
						data[k + gap] = data[k];
					data[k + gap] = temp;
				}
			}
		}
	}
}

int main()
{
	int data[] = { 3, 2, 5, 6, 4, 1, 9, 7, 8, 0 };
	int n = sizeof(data) / sizeof(int);
	ShellSort(data, n);
	for (int i = 0; i < n; ++i)
		cout << data[i] << " ";
	system("pause");
	return 0;
}