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

string ReverseSentence(string pString)
{
	if (pString.size()==0)
		return NULL;
	string::iterator pBegin = pString.begin();
	string::iterator pEnd = pString.end()-1;
	Reverse(pBegin, pEnd);
	pEnd = pBegin;
	while (pBegin != pString.end())
	{
		if (pEnd != pString.end() && *pEnd != ' ')
		{
			++pEnd;
		}
		else
		{
			--pEnd;
			Reverse(pBegin, pEnd);
			if ((++pEnd) != pString.end())
			{
				++pEnd;
				pBegin = pEnd;
			}
			else
			{
				pBegin = pEnd;
			}
		}
	}
	return pString;
}

void Test(const char *testName, string pString, string expected)
{
	cout << testName << " starts: ";
	if (ReverseSentence(pString) == expected)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

void Test1()
{
	Test("Test1", "I am a student.", "student. a am I");
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}