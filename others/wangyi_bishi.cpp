
//小易准备去魔法王国采购魔法神器, 购买魔法神器需要使用魔法币, 但是小易现在一枚魔法币都没有,
//但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
//魔法机器1 : 如果投入x个魔法币, 魔法机器会将其变为2x + 1个魔法币
//魔法机器2 : 如果投入x个魔法币, 魔法机器会将其变为2x + 2个魔法币
//小易采购魔法神器总共需要n个魔法币, 所以小易只能通过两台魔法机器产生恰好n个魔法币, 
//小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。

#include<iostream>
#include<stack>

			using namespace std;

int main(int argc, char **agrv)
{
	int number;
	cin >> number;
	if (number <= 0)
	{
		cout << "Invalid parameter!" << endl;
		return 0;
	}
	int mid = number;
	stack<char>result;
	while (mid != 0)
	{
		if (mid & 1 == 1)
			result.push('1');
		else
		{
			result.push('2');
			mid--;
		}
		mid = mid / 2;
	}
	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}
	return 0;
}



//为了得到一个数的"相反数", 我们将这个数的数字顺序颠倒, 然后再加上原先的数得到"相反数"。
//例如, 为了得到1325的"相反数", 首先我们将该数的数字顺序颠倒, 我们得到5231, 之后再加上原先的数, 
//我们得到5231 + 1325 = 6556.如果颠倒之后的数字有前缀零, 前缀零将会被忽略。例如n = 100, 颠倒之后是1.

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc, char **agrv)
{
	int number;
	cin >> number;
	if (number <= 0)
	{
		cout << "Invalid parameter!" << endl;
		return 0;
	}
	vector<int>bitNumber;
	int remain = number;
	int currentNumber;
	while (remain != 0)
	{
		currentNumber = remain % 10;
		remain /= 10;
		bitNumber.push_back(currentNumber);
	}
	int bit = bitNumber.size();
	int exp = bit;
	auto numBegin = bitNumber.begin();
	auto numEnd = bitNumber.end() - 1;
	int result = 0;
	for (int i = 0; i<bit; ++i)
	{
		result += (*numBegin + *numEnd)*pow(10, exp - 1);
		if (i != bit - 1)
		{
			numBegin++;
			numEnd--;
		}
		exp--;
	}
	cout << result << endl;
	return 0;
}



//一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。
//例如, "aaabbaaac"是由下面碎片组成的:'aaa', 'bb', 'c'。牛牛现在给定一个字符串,
//请你帮助计算这个字符串的所有碎片的平均长度是多少。

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int main(int argc, char **agrv)
{
	string s;
	cin >> s;
	if (s.empty())
	{
		cout << "Invalid parameter!" << endl;
		return 0;
	}
	vector<int>midResult;
	double result = 0;
	int count = 1;
	char currChar = *s.begin();
	if (s.size()>1)
	{
		for (auto c = s.begin() + 1; c != s.end(); ++c)
		{
			if (*c == currChar)
				count += 1;
			else
			{
				midResult.push_back(count);
				currChar = *c;
				count = 1;
			}
		}
		midResult.push_back(count);
		for (auto i = midResult.begin(); i<midResult.end(); ++i)
			result += *i;
		result /= midResult.size();
	}
	else
		result = 1;
	cout << setiosflags(ios::fixed);
	cout.precision(2);
	cout << result << endl;
	return 0;
}