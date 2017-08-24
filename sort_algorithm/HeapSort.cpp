#include<iostream>
#include<vector>

using namespace std;

void HeapAdjust(vector<int> &vec, int start, int end)
{
	int temp = vec[start];
	int i = 2 * start + 1; //�ýڵ�������������е�λ����� 
	while (i <= end)
	{
		//�ҳ����Һ����������Ǹ�
		if (i + 1 <= end&&vec[i] < vec[i + 1])
			++i;
		//������϶ѵĶ��壬���õ���λ��
		if (vec[i] < temp)
			break;
		//�����ӽڵ������ƶ����滻���丸�ڵ�
		vec[start] = vec[i];
		start = i;
		i = 2 * start + 1;
	}
	vec[start] = temp;
}

void HeapSort(vector<int> &vec, int end)
{
	int i; 
	//��һ����Ҷ�ӽڵ��λ�����Ϊ(len-1)/2
	for (i = (end - 1) / 2; i >= 0; --i)
		HeapAdjust(vec, i, end);
	for (i = end; i > 0; --i)
	{
		//�Ѷ�Ԫ�غ����һ��Ԫ�ؽ���λ�ã�  
		//��������һ��λ�ñ��������������  
		//ÿ��ѭ�����ν��δ����ֵ�ڷŽ���ǰ��һ��λ�ã�  
		//�����õ���˳����Ǵ�С����
		int temp = vec[i];
		vec[i] = vec[0];
		vec[0] = temp;
		//��arr[0...i-1]���µ���Ϊ���� 
		HeapAdjust(vec, 0, i - 1);
	}
}

int main(int argc, char **argv)
{
	vector<int>vec = { 3, 7, 6, 1, 2, 0, 9, 4 };
	HeapSort(vec, vec.size()-1);
	for (auto &i : vec)
		cout << i << " ";
	system("pause");
	return 0;
}