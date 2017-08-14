#include <iostream>
#include <vector>
#include <algorithm>
#include "005.h"

using namespace std;

template<typename T>
cplusplus::TreeNode<T> *  cplusplus::BinTree<T>::createBinTree(std::vector<T> data)
{
	vector<TreeNode<T> * >vec;
	for (vector<T>::iterator it = data.begin(); it != data.end(); ++it)
	{
		vec.push_back(new TreeNode<T>(*it));
	}
	for (decltype(vec.size())i = 0, pos = 0; pos != vec.size() - 1; ++i)
	{
		vec[i]->lc = vec[++pos];
		vec[i]->rc = vec[++pos];
	}
	return *vec.begin();
}

int main(int agrc, char *agrv[])
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	cplusplus::BinTree<int> tree;
	cplusplus::TreeNode<int> * root = tree.createBinTree(vec);//vec（带有模板参数）作为实参时，不要传迭代器
	cplusplus::Solution<int> s;
	cout << (s.IsBalanced(root)? "true" :"false")<< endl;
	system("pause");
	return 0;
}