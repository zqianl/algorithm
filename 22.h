#ifndef SOLUTION22_H
#define SOLUTION22_H

namespace cplusplus{
	template<typename T>
	struct TreeNode{
		T data;
		TreeNode<T> *lc;
		TreeNode<T> *rc;
		TreeNode(){}
		TreeNode(T x, TreeNode<T> *lc = NULL, TreeNode<T> *rc=NULL) : data(x), lc(lc), rc(rc){}
	};
	template<typename T>
	class Solution{
	public:
		int calMaxDepth(TreeNode<T> *root)
		{
			if (root == NULL)  return 0;
			return (1 + max(calMaxDepth(root->lc), calMaxDepth(root->rc)));
		}
	};
}

#endif

