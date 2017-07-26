#include<iostream>
#include<vector>
#include<map>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

bool flag = true;

struct data{
	double base;
	int exponent;
};

double PowerAbs(struct data base_exponent)
{
	if (base_exponent.exponent == 0)
		return 1.0;
	if (base_exponent.exponent == 1)
		return base_exponent.base;
	struct data base_exponent_1;
	base_exponent_1.base = base_exponent.base;
	base_exponent_1.exponent = base_exponent.exponent / 2;
	double result = PowerAbs(base_exponent_1);
	result *= result;
	if ((base_exponent.exponent %2) == 1)
		result *= base_exponent.base;
	return result;
}

double calPower(struct data base_exponent)
{
	if (base_exponent.base == 0.0&&base_exponent.exponent < 0)
	{
		flag = false;
		return 0.0;
	}
	else
	{
		int flagPosOrNeg = 1;
		if (base_exponent.exponent < 0)
		{
			base_exponent.exponent = -base_exponent.exponent;
			flagPosOrNeg = -1;
		}
		double answer = PowerAbs(base_exponent);
		if (flagPosOrNeg == -1)
			return 1 / answer;
		else
			return answer;
	}
}

int main(int argc,char*argv[])
{
	int num;
	vector<data> power_base;
	data data_1;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; i++)
	{
		cin >> data_1.base>>data_1.exponent;
		power_base.push_back(data_1);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	for (int i = 0; i < num; i++)
	{
		flag = true;
		double answer = calPower(*(power_base.begin() + i));
		if (flag)
			cout << answer << endl;
		else
			cout << "INF" << endl;
	}
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float> time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout.precision(6);
	cout << "³ÌÐòÓÃÊ±: "<<time_used.count() <<" Ãë"<< endl;
	std::system("pause");
	return 0;
}