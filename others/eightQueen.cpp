#include<stdio.h>  

//����8���ʺ��ܴ���ͬһ�У���ô�϶�ÿ���ʺ�ռ��һ�У��������Զ���һ������A[8]��
//�����е�i�����֣���A[i]��ʾλ�ڵ�i�еĻʺ���кš��Ȱ�����A[8]�ֱ���0 - 7��ʼ����
//�������Ը�������ȫ���У�����������0 - 7��7����ͬ�����ֳ�ʼ�����飬�������������
//��϶�Ҳ��ͬ�У���ô����ֻ��Ҫ�ж�ÿ�����ж�Ӧ��8���ʺ����Ƿ�������������ͬһ�Խ�
//���ϼ��ɣ�����������������±�i��j�����i - j == A[i] - A[j]��i - j == A[j] - A[i]��
//����Ϊ������Ԫ��λ����ͬһ���Խ����ϣ�������в�����������

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
����з��������İڷ�����ӡ�����еİڷ�������ʲôҲ����ӡ
*/
void CubVertex(int *A, int len, int begin)
{
	if (A == NULL || len != 8)
		return;

	if (begin == len - 1)
	{
		int i, j;
		bool can = true;    //�Ƿ��ַ��������İڷ�  
		for (i = 0; i<len; i++)
			for (j = i + 1; j<len; j++)
				if (i - j == A[i] - A[j] || i - j == A[j] - A[i])
				{
			//�������������һ���Խ����ϣ��򲻷���  
			can = false;
			break;
				}
		//�з��ϵİڷ����ʹ�ӡ����  
		if (can)
		{
			for (i = 0; i<len; i++)
				printf("%d ", A[i]);
			printf("\n");
		}
	}
	else
	{
		int i;
		for (i = begin; i<len; i++)
		{
			swap(&A[begin], &A[i]);
			CubVertex(A, len, begin + 1);
			swap(&A[begin], &A[i]);
		}
	}
}

int main()
{
	int A[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	CubVertex(A, 8, 0);
	return 0;
}