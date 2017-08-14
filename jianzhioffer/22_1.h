#ifndef SOLUTION22_1_H
#define SOLUTION22_1_H

namespace bintree{
	template<typename T>
	class TreeNode{
	public:
		T data;
		T lc;
		T rc;
		TreeNode(){}
		TreeNode(T data, T lc, T rc) :data(data), lc(lc), rc(rc){}
	};
	template<typename T>
	class Solution{
	public:
		int calMaxDepth(TreeNode<T> *root,T index)
		{
			if (root == NULL)
				return 0;
			if (index == -1)
				return 0;
			else
				return 1 + max(calMaxDepth(root, root[index].lc), calMaxDepth(root, root[index].rc));
		}
	};

}


#endif