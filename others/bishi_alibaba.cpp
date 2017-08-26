#include<iostream>
#include<math.h>

using namespace std;
//1/12/123/1234/12345/123456/1234567/12345678/123456789/123457891/1234578910/123456789101/1234567891011/...
//�����num�������Ǽ������10��Ϊ4
int GetNum(const int &num)
{
	int result;
	int i = 1;
	//�����ڵڼ���������
	while (i*(i + 1) / 2<num)
		++i;
	//�������еڼ�����
	int remainNum = num - i*(i - 1) / 2;
	if (remainNum <= 9) //��δ��������
	{
		result = remainNum;
	}
	else
	{
		int baseNum = 9;
		int weight = 1;
		int diff = remainNum - baseNum*weight;
		//�����Ǽ�λ��������1234...100101102֮����Ҫ�����֣���Ϊ��λ������
		while (diff > 0)
		{
			baseNum *= 10;
			weight += 1;
			diff -= baseNum*weight;
		}
		if (diff == 0) //diffΪ0���պ�Ϊĳһλ����������һ�����֣�����9
			result = 9;
		else
		{
			diff += baseNum*weight; //���赱ǰΪ��λ�����򣬴�ʱdiffΪ��λ������ĵڼ�������
			int num = diff / weight; //�����ǵڼ�����λ���Լ���Ӧ����������ʱ��λ����100��ʼ��
			int remainder = diff % weight;
			if (remainder == 1) //����Ϊ1���պ�Ϊ��һ����λ���İ�λ����num=121����Ϊ��λ���ĵ�122���İ�λ��
				result = num / pow(10, weight - 1) + 1;
			else
			{
				if (remainder == 0)   //����Ϊ0����Ϊ��ǰ��λ�������һλ����num=1����Ϊ100�����һλ����
				{
					num -= 1;
					remainder += weight;
				}
				int div = pow(10, weight - 1); //�������ֵĵڼ�λ�������ڴ�100��ʼ����121�����֣�ӦΪ221
				for (int i = 0; i < remainder - 1; ++i) //��ʱ�������һλ����˵ȼ�����num�ĵڼ�λ��
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

