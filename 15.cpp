#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;
/*
yes:
0 0 0 0 1
1 3 0 5 4
no:
0 1 1 2 3
1 3 4 5 7
*/
struct Poker{
	int num;
	vector<int>randomPoker;
};

int MyCompare(const void *data1, const void *data2)
{
	int *p1 = (int *)data1;
	int *p2 = (int *)data2;
	return *p1 - *p2;
}

bool IsStraight(const struct Poker &oneData)
{
	if (oneData.num > 13)
		return false;
	int pok[13];
	memset(pok, 0, 13*sizeof(int));
	for (int i = 0; i < oneData.num; ++i)
	{
		pok[i] = *(oneData.randomPoker.begin() + i);
	}
	qsort(pok, oneData.num, sizeof(int), MyCompare);
	int j = 0;
	while (j < oneData.num && pok[j] == 0)
	{
		++j;
	}
	if (j >= oneData.num-1)  //输入全为0
		return true;
	else  //j即为第一张不为0的牌
	{
		int numZero = j;
		int sumDiff = 0;
		int minDiff = oneData.num - 1 - j;
		while (j <= (oneData.num - 2))
		{
			int diff = pok[j + 1] - pok[j];
			if (diff == 0)//除0外有相等的牌
				return false;
			else
			{
				sumDiff += diff;
				++j;
			}
		}
		if (numZero >= sumDiff - minDiff)
			return true;
		else
			return false;
	}
}

int main(int argc, char*argv[])
{
	int m;
	int random;
	Poker poker;
	vector<Poker>data;
	while (1)
	{
		cin >> m;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (m != 0)
		{
			poker.num = m;
			for (int i = 0; i < m; ++i)
			{
				cin >> random;
				poker.randomPoker.push_back(random);
			}
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			data.push_back(poker);
		}
		else
			break;
	}
	cout << "output:" << endl;
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		bool result = IsStraight(*i);
		if (result)
			cout << "So Lucky!" << endl;
		else
			cout << "My God!" << endl;
	}
	system("pause");
	return 0;
}