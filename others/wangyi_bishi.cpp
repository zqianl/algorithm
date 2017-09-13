
//С��׼��ȥħ�������ɹ�ħ������, ����ħ��������Ҫʹ��ħ����, ����С������һöħ���Ҷ�û��,
//����С������̨ħ����������ͨ��Ͷ��x(x����Ϊ0)��ħ���Ҳ��������ħ���ҡ�
//ħ������1 : ���Ͷ��x��ħ����, ħ�������Ὣ���Ϊ2x + 1��ħ����
//ħ������2 : ���Ͷ��x��ħ����, ħ�������Ὣ���Ϊ2x + 2��ħ����
//С�ײɹ�ħ�������ܹ���Ҫn��ħ����, ����С��ֻ��ͨ����̨ħ����������ǡ��n��ħ����, 
//С����Ҫ��������һ��Ͷ�뷽��ʹ�����ǡ��ӵ��n��ħ���ҡ�

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



//Ϊ�˵õ�һ������"�෴��", ���ǽ������������˳��ߵ�, Ȼ���ټ���ԭ�ȵ����õ�"�෴��"��
//����, Ϊ�˵õ�1325��"�෴��", �������ǽ�����������˳��ߵ�, ���ǵõ�5231, ֮���ټ���ԭ�ȵ���, 
//���ǵõ�5231 + 1325 = 6556.����ߵ�֮���������ǰ׺��, ǰ׺�㽫�ᱻ���ԡ�����n = 100, �ߵ�֮����1.

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



//һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�
//����, "aaabbaaac"����������Ƭ��ɵ�:'aaa', 'bb', 'c'��ţţ���ڸ���һ���ַ���,
//���������������ַ�����������Ƭ��ƽ�������Ƕ��١�

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