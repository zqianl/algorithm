#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

long long CalOneNum(long long a)
{
	long long count = 0;
	long long curr;
	long long base = 1;
	long long remain = 0;
	while (a)
	{
		curr = a % 10;
		a /= 10;
		if (curr == 1)
			count += a*base + remain + 1;
		else if (curr > 1)
			count += (a + 1)*base;
		else
			count += a*base;
		remain += curr*base;
		base *= 10;
	}
	return count;
}

int main(int argc, char*argv[])
{
	long long m,n;
	cin >> m >> n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	long long result;
	if (m > n)
		result = CalOneNum(m) - CalOneNum(n-1);
	else
		result = CalOneNum(n) - CalOneNum(m-1);
	cout << result << endl;
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << time_used.count() << endl;
	system("pause");
	return 0;
}