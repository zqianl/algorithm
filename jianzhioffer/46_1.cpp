#include<iostream>
#include<set>
#include<functional>
#include<vector>
#include<sstream>

using namespace std;

multiset<int,greater<int>> MinNumData(int *data, int length, unsigned int minNum)
{
	if (data == NULL || length <= 0 || minNum <= 0)
		throw new std::exception("Invalid Parameters");
	multiset<int, greater<int>>result;
	result.clear();
	for (int i = 0; i < length; ++i)
	{
		if (result.size() < minNum)
			result.insert(data[i]);
		else
		{
			if (data[i] < *(result.begin()))
			{
				multiset<int, greater<int>>::iterator iterResult = result.begin();
				result.erase(iterResult);
				result.insert(data[i]);
			}
			
		}
	}
	return result;
}

void Test(const char *testName, int *data, int length, int minNum)
{
	cout << testName << " starts: ";
	multiset<int,greater<int>> intSet = MinNumData(data, length, minNum);
	for (auto &i : intSet)
		cout << i << " ";
	cout << endl;
}

void Test1()
{
	int minNum = 4;
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("Test1", data, sizeof(data) / sizeof(int), minNum);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}