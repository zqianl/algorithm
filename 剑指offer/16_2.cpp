#include<stdio.h>  
#include<math.h>  
#include<stdbool.h>  
bool can;

//http://blog.csdn.net/ns_code/article/details/27823291
/*
��ӡ��Start��ʼ������n����������
*/
void PrintSequence(int start, int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%d", start + i);
		if (i == n - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/*
�ҵ���Ϊs��������������
*/
void FindSumSequence(int s)
{
	int i;
	//�����iΪҪ������������ĸ���������Ϊ2  
	for (i = (int)sqrt(double(2 * s)); i >= 2; i--)
	{
		if ((2 * s) % i == 0)
		{
			int DoubleStart = 2 * s / i - i + 1;
			if ((DoubleStart & 1) == 0)    //���Ϊż��  
			{
				can = true;
				PrintSequence(DoubleStart / 2, i);
			}
		}
	}
}

int main()
{
	int s;
	while (scanf("%d", &s) != EOF && s >= 0)
	{
		can = false;
		FindSumSequence(s);
		if (!can)
			printf("Pity!\n");
		printf("#\n");
	}
	return 0;
}