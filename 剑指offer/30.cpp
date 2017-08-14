#include<iostream>
#include<algorithm>
#include<limits>
#include<numeric>

#include"004.h"

// Create a tree for test
//            1
//           / \
//          2  3
//         / \  \
//        4  5  6
//       / \
//      7  8
//        /
//       9

using namespace std;

int main(int argc, char *argv[])
{
	cplusplus::TreeNode<int> root(1);
	cplusplus::TreeNode<int> t2(2);
	cplusplus::TreeNode<int> t3(3);
	cplusplus::TreeNode<int> t4(4);
	cplusplus::TreeNode<int> t5(5);
	cplusplus::TreeNode<int> t6(6);
	cplusplus::TreeNode<int> t7(7);
	cplusplus::TreeNode<int> t8(8);
	cplusplus::TreeNode<int> t9(9);

	root.lc = &t2;
	root.rc = &t3;
	t2.lc = &t4;
	t2.rc = &t5;
	t3.rc = &t6;
	t4.lc = &t7;
	t4.rc = &t8;
	t8.lc = &t9;

	cplusplus::Solution<int> s;
	cout << "the MaxDepth is: " ;
	cout << s.calMaxDepth(&root) << endl;
	system("pause");
	return 0;
}