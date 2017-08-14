#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

/*ʵ�������⼸�ֲ��ԣ�
1������������Ƚϣ����Ӷ�o(n^2)
2��������Ȼ������Ƚϣ����ÿ��������Ӷ�o(nlogn)
3����λ���ɨ�裬�������һλ�ϣ��ֳ�Ϊ0��Ϊ1������������
���ڸ��Ե������Ͻ��еڶ�λɨ�裬�ٷ֣�ֱ���ֳ�������Ϊֹ
*/
void FindTwoSingle(vector<int> &vec, vector<int>&result)
{
	int midResult = 0;
	for (auto i = vec.begin(); i < vec.end(); ++i)
		midResult = midResult ^ (*i);
	//�ҵ�midResult�����ұ߲�Ϊ0��һλ,������a&(~a+1)�����Ϊ2^(n-1)
	int notZero = midResult&(~midResult + 1);
	//���յ�ǰλ��1��0�ֳ�����vector
	//����жϵ�ǰλ��1����0������Ϊ�ұߵ�nλ����a&(~a+2^(n-1))==a?
	//�����ķ�����a&(2^(n-1))==0?
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
//�ڶ��ֲ��� http://blog.csdn.net/ns_code/article/details/27800577

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