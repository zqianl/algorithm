#ifndef SOLUTION3_H
#define SOLUTION3_H

namespace cplusplus
{
	using namespace std;

	template<typename T> 
	class Solution{
	public:
		bool findNumber(vector<vector<T>>&matrix, T&target,int &m,int &n)
		{
			int low = 0,high=m*n-1;
			while (low < high)
			{
				int mid = (high + low) >> 1;
				if (matrix[mid / n][mid % n] > target)
					high = mid;
				else if (matrix[mid / n][mid % n] < target)
					low = mid + 1;
				else
					return true;
			}
			return matrix[mid / n][mid%n] == target;
		}
	};

}

#endif
