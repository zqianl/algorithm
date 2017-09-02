#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int g_maxValue = 6;

// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
	if (number < 1)
		return;

	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;

	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i)
	{
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; ++i)
	{
		Probability(number, number, i, pProbabilities);
		for (int j = 0; j < number * g_maxValue - number + 1; ++j)
		{
			cout << pProbabilities[j] << " ";
		}
		cout << endl;
	}
}

void Probability(int original, int current, int sum,
	int* pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
	if (number < 1)
		return;
	vector<vector<int>>pProbabilities(2,vector<int>(g_maxValue*number+1,0));
	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;
	for (int k = 2; k <= number; ++k)
	{
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;
		for (int i = k; i <= g_maxValue*k; ++i)
		{
			for (int j = 1; j <= i&&j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}
		flag = 1 - flag;
	}
	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue*number; ++i)
	{
		double ratio = (double)pProbabilities[flag][i] / total;
		cout << i<<" : "<<ratio <<endl;
	}
}

void Test1(int num)
{
	printf("Test for solution1\n");
	PrintProbability_Solution2(num);
}

int main(int argc, char **argv)
{
	Test1(3);
	system("pause");
	return 0;
}