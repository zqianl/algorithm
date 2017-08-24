#include<iostream>
#include<stack>

using namespace std;

bool IsPopOrder(const int *pushData, const int *popData, int length)
{
	bool result = false;
	if (pushData != NULL&&popData != NULL&&length > 0)
	{
		const int *nextPush = pushData;
		const int *nextPop = popData;
		stack<int> stackData;
		while (nextPop - popData < length)
		{
			while (stackData.empty() || stackData.top() != *nextPop)
			{
				if (nextPush - pushData == length)
					break;
				stackData.push(*nextPush);
				nextPush++;
			}
			if (stackData.top() != *nextPop)
				break;

			stackData.pop();
			nextPop++;
		}
		if (stackData.empty() && nextPop - popData == length)
			result = true;
	}
	return result;
}

void Test(const char *testName, const int *pushData, const int *popData, int length,bool expected)
{
	if (testName != NULL)
		cout << testName << " begins: ";
	if (IsPopOrder(pushData, popData, length) == expected)
		cout << "passed!" << endl;
	else
		cout << "failed" << endl;
}

void Test1()
{
	int pushData[] = { 1, 2, 3, 4, 5 };
	int popData[] = { 4, 5, 3, 2, 1 };
	Test("Test1",pushData, popData, sizeof(pushData)/sizeof(int),true);
}

int main(int argc, char **argv)
{
	Test1();
	system("pause");
	return 0;
}