#include<stdio.h>  
#include<stdbool.h>  
bool can;

//http://blog.csdn.net/ns_code/article/details/27823291

void FindSumSequence(int s)
{
	int start = 1;
	int end = 2;
	int mid = (1 + s) >> 1;
	int cursum = start + end;

	while (start < mid)
	{
		if (cursum == s)
		{
			can = true; 
			int i;
			for (i = start; i <= end; i++)
			{
				printf("%d", i);
				if (i == end)
					printf("\n");
				else
					printf(" ");
			}
			end++;
			cursum += end;
		}
		else if (cursum < s)
		{
			end++;
			cursum += end;
		}
		else
		{
			cursum -= start;
			start++;
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