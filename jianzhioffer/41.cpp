#include<iostream>
#include<sstream>

using namespace std;

bool VerifySquenceOfBST(int squence[], int length)
{
	if (squence == NULL&&length<=0)
		return false;
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (squence[i]>squence[length - 1])
			break;
	}
	for (int j = i; j < length - 1; ++j)
	{
		if (squence[j] < squence[length - 1])
			return false;
	}
	bool left = true;
	if (i > 0)
	{
		left = VerifySquenceOfBST(squence, i - 1);
	}
	bool right = true;
	if (i < length - 1)
	{
		right = VerifySquenceOfBST(squence + i, length - i - 1);
	}
	return left && right;

}

void Test(const char *str,int squence[],int length,bool expected)
{
	cout << str << " starts: ";
	if (VerifySquenceOfBST(squence, length) == expected)
	{
		cout << "passed!" << endl;
	}
	else
	{
		cout << "failed!" << endl;
	}
}


void Test1()
{
	int squence[] = { 5, 7, 6, 9, 11, 10, 8 };
	Test("Test1", squence, sizeof(squence) / sizeof(int), true);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}