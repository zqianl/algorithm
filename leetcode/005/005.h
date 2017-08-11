#ifndef SOLUTION005_H
#define SOLUTION005_H

namespace cplusplus{
	template<typename T>
	struct TreeNode{
		T data;
		TreeNode<T> *  lc;
		TreeNode<T> *  rc;
		TreeNode(T x) :data(x), lc(NULL), rc(NULL){}
	};

	template<typename T>
	class BinTree{
	public:
		TreeNode<T> *  createBinTree(std::vector<T> data);
		//{
		//	vector<TreeNode<T> * >vec;
		//	for (vector<T>::iterator it = data.begin(); it != data.end(); ++it)
		//	{
		//		vec.push_back(new TreeNode<T>(*it));
		//	}
		//	for (decltype(vec.size())i = 0, pos = 0; pos != vec.size() - 1; ++i)
		//	{
		//		vec[i]->lc = vec[++pos];
		//		vec[i]->rc = vec[++pos];
		//	}
		//	return *vec.begin();
		//}
	};

	//template<typename T>
	//TreeNode<T> *  BinTree<T>::createBinTree(std::vector<T> data)
	//{
	//	vector<TreeNode<T> * >vec;
	//	for (vector<T>::iterator it = data.begin(); it != data.end(); ++it)
	//	{
	//		vec.push_back(new TreeNode<T>(*it));
	//	}
	//	for (decltype(vec.size())i = 0, pos = 0; pos != vec.size() - 1; ++i)
	//	{
	//		vec[i]->lc = vec[++pos];
	//		vec[i]->rc = vec[++pos];
	//	}
	//	return *vec.begin();
	//}

	template<typename T>
	class Solution{
	public:
		bool IsBalanced(TreeNode<T> *  root)
		{
			calNodeHeight(root);
			return balanceOrNot;
		}
	private:
		int calNodeHeight(TreeNode<T> * node)
		{
			if (node == NULL || !balanceOrNot)
				return 0;
			else
			{
				int leftHeight = calNodeHeight(node->lc);
				int rightHeight = calNodeHeight(node->rc);
				if (std::abs(leftHeight - rightHeight) > 1)
					balanceOrNot = false;
				return max(leftHeight, rightHeight) + 1;
			}	
		}
		bool balanceOrNot = true;
	};

}

#endif




