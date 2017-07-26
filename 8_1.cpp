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

double square(double a)
{
	return a*a;
}

int multi_2(int a)
{
	return 2*a;
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
		double power_answer = 1.0;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		vector<int>power_sum;
		if (base_exponent.exponent == 0)
			return power_answer;
		else
		{
			int flagPosOrNeg = 1;
			if (base_exponent.exponent < 0)
			{
				flagPosOrNeg = -1;
				base_exponent.exponent = -base_exponent.exponent;
			}
			map<int, int>power_2;
			power_2.insert(pair<int, int>(0,1));
			int j = 0;
			int diff = base_exponent.exponent - power_2[j];
			int p;
			while (diff > 0)
			{
				diff += power_2[j];
				p = multi_2(power_2[j]);
				j++;
				power_2.insert(pair<int, int>{j, p});
				diff = diff - power_2[j];
			}
			if (diff == 0)
				power_sum.push_back(j);
			else
			{
				j--;
				power_sum.push_back(j);
				diff = diff + power_2[j + 1] - power_2[j];
				while (1)
				{
					j--;
					diff -= power_2[j];
					if (diff > 0)
						power_sum.push_back(j);
					else if (diff == 0)
					{
						power_sum.push_back(j);
						break;
					}
					else
						diff += power_2[j];
				}
			}
			int m = 1;
			if (*(power_sum.end() - 1) == 0)
			{
				power_answer = base_exponent.base;
				m++;
			}
			if (power_sum.size() != 1 || (power_sum.size() == 1 && *(power_sum.end() - 1) != 0))
			{
				double result = base_exponent.base;
				for (int k = 1; k <= *power_sum.begin(); k++)
				{
					result = square(result);
					if (k == *(power_sum.end() - m))
					{
						power_answer *= result;
						m++;
					}
				}
			}
			power_sum.clear();
			power_2.clear();
			if (flagPosOrNeg ==1)
				return power_answer;
			else
				return 1 / power_answer;
		}
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