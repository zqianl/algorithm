#include<iostream>

using namespace std;

void Merge(int a[], int start, int mid, int end, int p[])
{
	int i = start, j = mid + 1;
	int k = 0;
	while (i <= mid&&j <= end)
	{
		if (a[i] <= a[j])
			p[k++] = a[i++];
		else
			p[k++] = a[j++];
	}
	while (i <= mid)
		p[k++] = a[i++];
	while (j <= end)
		p[k++] = a[j++];
	for (int i = 0; i < k; ++i)
		a[start + i] = p[i];
}

void MergeSort(int a[], int start, int end, int p[])
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(a, start, mid, p);
		MergeSort(a, mid + 1, end, p);
		Merge(a, start, mid, end, p);
	}
}


int main(int argc, char **argv)
{
	int a[] = { 3, 5, 2, 6, 1, 7, 8, 4, 9 };
	int n = sizeof(a) / sizeof(int);
	int *p = new int[n];
	if (p == NULL)
		return false;
	MergeSort(a, 0, n - 1, p);
	int i = 0;
	while (i < n)
	{
		cout << *(a + i) << " ";
		i++;
	}
	delete[] p;
	system("pause");
	return 0;
}