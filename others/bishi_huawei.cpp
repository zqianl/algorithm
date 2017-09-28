//�����ַ������������ַ����й�ͬ���ֵ��ַ����� '_'
#include <iostream>
#include<vector>
#include<string>
#include<set>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	string string1, string2;
	cin >> string1;
	cin >> string2;
	vector<int> vecMap(256,0);
	set<int>commonChar;
	for (auto i = string1.begin(); i != string1.end(); ++i)
	{
		vecMap[*i]++;
	}
	for (auto i = string2.begin(); i != string2.end(); ++i)
	{
		if (vecMap[*i] != 0)
			commonChar.insert(*i);
	}
	for (auto i = string1.begin(); i != string1.end(); ++i)
	{
		if (commonChar.find(*i) != commonChar.end())
			*i = '_';
	}
	for (auto i = string2.begin(); i != string2.end(); ++i)
	{
		if (commonChar.find(*i) != commonChar.end())
			*i = '_';
	}
	cout << string1 << endl;
	cout << string2 << endl;
	system("pause");
	return 0;
}

//ISBN�ţ�����1-234-56789�͵�11���ַ���ɵ��ַ������ֱ𽫾Ÿ��������1-9��
//Ȼ��mod 11������a����ʾ�����a����10�����1-234-56789-X,�������1-234-56789-a
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
	string str;
	cin >> str;
	if (str.size() != 11)
		cout << "ERROR" << endl;
	else
	{
		if (str[1] != '-' || str[5] != '-')
			cout << "ERROR" << endl;
		else
		{
			int j = -1;
			bool flag = true;
			for (auto i = str.begin(); i != str.end(); ++i)
			{
				j++;
				if (j != 1 && j != 5)
				{
					if (*i > '9' || *i < '0')
					{
						flag = false;
						break;
					}
				}
			}
			if (flag == false)
				cout << "ERROR" << endl;
			else
			{
				int sum = 0;
				sum += (str[0] - '0') + (str[2] - '0') * 2 + (str[3] - '0') * 3 + (str[4] - '0') * 4 + (str[6] - '0') * 5
					+ (str[7] - '0') * 6 + (str[8] - '0') * 7 + (str[9] - '0') * 8 + (str[10] - '0') * 9;
				int last = sum % 11;
				if (last == 10)
					last = 'X';
				else
					last = last + '0';
				str.push_back('-');
				str.push_back(last);
				cout << str << endl;
			}
		}
	}
	system("pause");
	return 0;
}

//������������qwe.ert|asd.xcv.sdf|ert.tyu.dfg�����룬�������һ��.֮����ַ����ֵ����������
//��������ٱȽ�ǰһ����������ǰһ���ַ��������ĳһ������û��ǰһ��������������һ��ǰ��
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool JudgeSwap(string str1, string str2)
{
	bool flag = false;
	vector<string>vecStr1;
	vector<string>vecStr2;

	auto k = str1.begin();
	for (auto i = str1.begin(); i != str1.end(); ++i)
	{
		if (*i == '.')
		{
			string midString1(k, i);
			vecStr1.push_back(midString1);
			k = i + 1;
		}
	}
	string midString1(k, str1.end());
	vecStr1.push_back(midString1);

	k = str2.begin();
	for (auto i = str2.begin(); i != str2.end(); ++i)
	{
		if (*i == '.')
		{
			string midString2(k, i);
			vecStr2.push_back(midString2);
			k = i + 1;
		}
	}
	string midString2(k, str2.end());
	vecStr2.push_back(midString2);

	auto i = vecStr1.end() - 1;
	auto j = vecStr2.end() - 1;
	bool midFlag = false;
	for (; i != vecStr1.begin() && j != vecStr2.begin(); i--, j--)
	{
		if (*i > *j)
		{
			flag = true;
			midFlag = true;
			break;
		}
		else if(*i < *j)
		{
			midFlag = true;
			break;
		}
	}
	if (midFlag == false)
	{
		if (*i > *j)
		{
			flag = true;
		}
		else
		{
			if (j == vecStr2.begin())
			{
				flag = true;
			}
		}
	}
	return flag;
}

void Swap(string &str1, string &str2)
{
	string midStr = str1;
	str1 = str2;
	str2 = midStr;
}

int main(int argc, char **argv)
{
	string str;
	cin >> str;
	vector<string>vecComStr;
	auto j = str.begin();
	for (auto i = str.begin(); i != str.end(); ++i)
	{
		if (*i == '|')
		{
			string midString(j,i);
			vecComStr.push_back(midString);
			j = i + 1;
		}
	}
	string midString(j, str.end());
	vecComStr.push_back(midString);
	for (unsigned int i = 0; i < vecComStr.size(); ++i)
	{
		for (unsigned int j = 0; j < vecComStr.size() - i - 1; ++j)
		{
			bool flag = JudgeSwap(vecComStr[j], vecComStr[j+1]);
			if (flag == true)
				Swap(vecComStr[j], vecComStr[j+1]);
		}
	}
	for (auto i = vecComStr.begin(); i != vecComStr.end(); ++i)
	{
		cout << *i;
		if (i != vecComStr.end() - 1)
			cout << '|';
	}
	system("pause");
	return 0;
}



