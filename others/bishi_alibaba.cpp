#include<iostream>
#include<math.h>

using namespace std;
//1/12/123/1234/12345/123456/1234567/12345678/123456789/123457891/1234578910/123456789101/1234567891011/...
//计算第num个数字是几，如第10个为4
int GetNum(const int &num)
{
	int result;
	int i = 1;
	//计算在第几个序列中
	while (i*(i + 1) / 2<num)
		++i;
	//该序列中第几个数
	int remainNum = num - i*(i - 1) / 2;
	if (remainNum <= 9) //尚未出单个数
	{
		result = remainNum;
	}
	else
	{
		int baseNum = 9;
		int weight = 1;
		int diff = remainNum - baseNum*weight;
		//计算是几位数区域，如1234...100101102之后是要求数字，则为三位数区域
		while (diff > 0)
		{
			baseNum *= 10;
			weight += 1;
			diff -= baseNum*weight;
		}
		if (diff == 0) //diff为0，刚好为某一位数区域的最后一个数字，等于9
			result = 9;
		else
		{
			diff += baseNum*weight; //假设当前为三位数区域，此时diff为三位数区域的第几个数字
			int num = diff / weight; //计算是第几个三位数以及相应的余数（此时三位数从100开始）
			int remainder = diff % weight;
			if (remainder == 1) //余数为1，刚好为下一个三位数的百位（如num=121，则为三位数的第122个的百位）
				result = num / pow(10, weight - 1) + 1;
			else
			{
				if (remainder == 0)   //余数为0，则为当前三位数的最后一位（如num=1，则为100的最后一位数）
				{
					num -= 1;
					remainder += weight;
				}
				int div = pow(10, weight - 1); //计算数字的第几位数，由于从100开始，第121个数字，应为221
				for (int i = 0; i < remainder - 1; ++i) //此时不计算第一位，因此等价于求num的第几位数
				{
					num = num % div;
					--weight;
					div = pow(10, weight - 1);
				}
				result = num / div;
			}
		}
	}
	return result;
}

int main()
{
	int num;
	cin >> num;
	int result = GetNum(num);
	cout << result << endl;
	system("pause");
	return 0;
}

