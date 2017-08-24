#include<iostream>
#include<vector>

using namespace std;

void HeapAdjust(vector<int> &vec, int start, int end)
{
	int temp = vec[start];
	int i = 2 * start + 1; //该节点的左孩子在数组中的位置序号 
	while (i <= end)
	{
		//找出左右孩子中最大的那个
		if (i + 1 <= end&&vec[i] < vec[i + 1])
			++i;
		//如果符合堆的定义，则不用调整位置
		if (vec[i] < temp)
			break;
		//最大的子节点向上移动，替换掉其父节点
		vec[start] = vec[i];
		start = i;
		i = 2 * start + 1;
	}
	vec[start] = temp;
}

void HeapSort(vector<int> &vec, int end)
{
	int i; 
	//第一个非叶子节点的位置序号为(len-1)/2
	for (i = (end - 1) / 2; i >= 0; --i)
		HeapAdjust(vec, i, end);
	for (i = end; i > 0; --i)
	{
		//堆顶元素和最后一个元素交换位置，  
		//这样最后的一个位置保存的是最大的数，  
		//每次循环依次将次大的数值在放进其前面一个位置，  
		//这样得到的顺序就是从小到大
		int temp = vec[i];
		vec[i] = vec[0];
		vec[0] = temp;
		//将arr[0...i-1]重新调整为最大堆 
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