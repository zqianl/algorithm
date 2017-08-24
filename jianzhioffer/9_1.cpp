#include<iostream>

using namespace std;

int numPrint = 1;

void PrintNumber(char *number)
{
	int i = 0;
	while (number[i] == '0')
		++i;
	for (; i < strlen(number); ++i)
		cout << number[i];
	if (numPrint != 1)
	{
		numPrint += 1;
		cout << endl;
	}
	else
		numPrint += 1;
}

void Print1ToMaxOfDigitsRe(char *number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfDigitsRe(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfDigitsRe(number, n, 0);
	}
	delete []number;
}

int main(int argc, char **argv)
{
	int num;
	cin >> num;
	Print1ToMaxOfNDigits(num);
	system("pause");
	return 0;
}