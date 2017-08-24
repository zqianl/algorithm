#include<iostream>
#include<vector>

using namespace std;

void Record(vector<int> &vec, int length, bool(*func)(const int &a))
{
	if (vec.size() == 0)
		return;
	vector<int>::iterator start = vec.begin();
	vector<int>::iterator end = vec.end() - 1;
	while (start < end)
	{
		while (start < end && func(*start))
			start++;
		while (end > start && !func(*end))
			end--;
		if (start < end)
		{
			int temp = *start;
			*start = *end;
			*end = temp;
		}
	}
}

bool OddOrEven(const int &a)
{
	return (a & 1) == 1;
}

void RecordOddEven(vector<int> &vec, int length)
{
	Record(vec, length, OddOrEven);
}

int main(int argc, char **argv)
{
	vector<int>vec{ 1, 2, 3, 4, 5, 6, 7, 8 };
	RecordOddEven(vec, vec.size());
	for (auto &i : vec)
		cout << i << " ";
	system("pause");
	return 0;
}