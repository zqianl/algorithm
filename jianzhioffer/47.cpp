#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

char FirstNotRepeatChar(char *pString)
{
	if (pString == NULL)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));
	char *pHashKey = pString;
	while (*pHashKey != '\0')
	{
		hashTable[*(pHashKey)]++;
		pHashKey++;
	}
	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}

void Test(const char *testName, char *pString, char expected)
{
	cout << testName << " starts: ";
	if (FirstNotRepeatChar(pString) == expected)
		cout << "passed!" << endl;
	else
		cout << "failed!" << endl;
}

void Test1()
{
	Test("Test1", "google", 'l');
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}