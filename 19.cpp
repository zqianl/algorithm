#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

void FindTwoSingle(vector<int> &vec, vector<int>&result)
{
	int midResult = 0;
	for (auto i = vec.begin(); i < vec.end(); ++i)
		midResult = midResult ^ (*i);
	//找到midResult中最右边不为0的一位,方法：a&(~a+1)，结果为2^(n-1)
	int notZero = midResult&(~midResult + 1);
	//按照当前位是1或0分成两个vector
	//如何判断当前位是1还是0：假设为右边第n位，则a&(~a+2^(n-1))==a?
	//更简便的方法：a&(2^(n-1))==0?
	int a = 0, b = 0;
	for (auto i = vec.begin(); i < vec.end(); ++i)
	{
		if (((*i)&(~(*i) + notZero)) == notZero)
			a ^= (*i);
		else
			b ^= (*i);
	}
	result.push_back(a);
	result.push_back(b);
}
//第一种策略,http://zhedahht.blog.163.com/blog/static/25411174201283084246412/
int FindLastBit(const int &a)
{
	return a&(~a + 1);
}

vector<int> FindThreeSingle(vector<int> &member)
{
	int xorResult = 0;
	for (auto i = member.begin(); i < member.end(); ++i)
	{
		xorResult ^= *i;
	}
	int flag = 0;
	for (auto i = member.begin(); i < member.end(); ++i)
	{
		flag ^= FindLastBit(xorResult ^ (*i));
	}
	flag = FindLastBit(flag);
	int first = 0;
	for (auto i = member.begin(); i < member.end(); ++i)
	{
		if (FindLastBit(xorResult ^ (*i))==flag)
			first ^= *i;
	}
	vector<int>result;
	result.push_back(first);
	for (auto i = member.begin(); i < member.end(); ++i)
	{
		if (*i == first)
		{
			member.erase(i);
			break;
		}
	}
	FindTwoSingle(member, result);
	return result;
}


int main(int argc, char*argv[])
{
	int num;
	int elem;
	vector<int>data;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; ++i)
	{
		cin >> elem;
		data.push_back(elem);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	vector<int> result = FindThreeSingle(data);
	for (auto i = result.begin(); i < result.end(); ++i)
		cout << *i << " ";
	cout << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << time_used.count() << endl;
	system("pause");
	return 0;
}