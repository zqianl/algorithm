#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

void Reverse(string::iterator pBegin, string::iterator pEnd)
{
	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

string ReverseSentence(string pString,int numReverse)
{
	if (numReverse<0||numReverse>pString.size())
		throw new std::exception("Invalid Parameters");
	if (pString.size() == 0)
		return NULL;
	string::iterator pBegin = pString.begin();
	string::iterator pMiddle = pBegin + numReverse - 1;
	string::iterator pEnd = pString.end()-1;
	Reverse(pBegin, pMiddle);
	Reverse(pMiddle + 1, pEnd);
	Reverse(pBegin, pEnd);
	return pString;
}

void Test(const char *testName, string pString, int numReverse,string expected)
{
	cout << testName << " starts: ";
	if (ReverseSentence(pString, numReverse) == expected)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

void Test1()
{
	Test("Test1", "hello world", 3,"lo worldhel");
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}