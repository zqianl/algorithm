#include<iostream>
#include<string>

using namespace std;

void Permutation(char *str, char *pBegin)
{
	if (*pBegin == '\0')
		cout << str << " ";
	else
	{
		for (char *ch = pBegin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;

			Permutation(str, pBegin + 1);

			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char *str)
{
	if (str == NULL)
		return;
	Permutation(str, str);
}

int main(int argc, char **argv)
{
	char str[] = "abcd";
	Permutation(str);
	system("pause");
	return 0;
}