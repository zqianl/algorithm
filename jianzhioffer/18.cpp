#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

vector<int> FindTwoSingle(vector<int> &vec)
{
	int midResult = 0;
	for (auto i = vec.begin(); i < vec.end(); ++i)
		midResult = midResult ^ (*i);
	//�ҵ�midResult�����ұ߲�Ϊ0��һλ,������a&(~a+1)�����Ϊ2^(n-1)
	int notZero = midResult&(~midResult + 1);
	//���յ�ǰλ��1��0�ֳ�����vector
	//����жϵ�ǰλ��1����0������Ϊ�ұߵ�nλ����a&(~a+2^(n-1))==a?
	//�����ķ�����a&(2^(n-1))==0?
	int a=0, b = 0;
	for (auto i = vec.begin(); i < vec.end(); ++i)
	{
		if (((*i)&(~(*i) + notZero)) == notZero)
			a^=(*i);
		else
			b^=(*i);
	}
	vector<int>result;
	if (a > b)
	{
		result.push_back(b);
		result.push_back(a);
	}
	else
	{
		result.push_back(a);
		result.push_back(b);
	}
	return result;
}

int main(int argc, char*argv[])
{
	int num;
	int elem;
	vector<int>data;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num;++i)
	{
		cin >> elem;
		data.push_back(elem);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	vector<int> result = FindTwoSingle(data);
	for (auto i = result.begin(); i < result.end(); ++i)
		cout << *i << " ";
	cout << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << time_used.count() << endl;
	system("pause");
	return 0;
}