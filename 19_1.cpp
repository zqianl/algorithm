#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

/*实际上另外几种策略：
1）遍历，逐个比较：复杂度o(n^2)
2）先排序，然后逐个比较：采用快速排序复杂度o(nlogn)
3）按位逐个扫描，如在最后一位上，分成为0和为1的两个向量，
再在各自的向量上进行第二位扫描，再分，直到分出三个数为止
*/
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
//第二种策略 http://blog.csdn.net/ns_code/article/details/27800577

vector<int> FindThreeSingle(vector<int> &member)
{
	int count1 = 0;
	int count0 = 0;
	int temp1 = 0;
	int temp0 = 0;
	int first;
	for (int i = 0; i < sizeof(int); ++i)
	{
		count1 = count0 = temp1 = temp0 = 0;
		for (auto j = member.begin(); j != member.end(); ++j)
		{
			if (*j ^ (1 << i))
			{
				count1 += 1;
				temp1 ^= *j;
			}
			else
			{
				count0 += 1;
				temp0 ^= *j;
			}
		}
		if (count1 & 1)
		{
			if (temp0 == 0)
				continue;
			else
				first = temp1;
		}
		else
		{
			if (temp1 == 0)
				continue;
			else
				first = temp0;
		}
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