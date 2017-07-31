#include<limits>
#include<numeric>
#include<chrono>
#include"solution.h"

using namespace std;

int main(int argc, char*argv[])
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int>data;
	Solution<int> s;
	int element;
	for (int i = 0; i < num; i++)
	{
		cin >> element;
		data.push_back(element);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	cout << s.singleNumber(data, num) << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << time_used.count() << endl;
	std::system("pause");
	return 0;
	
}

