#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

class Solution{
public:
	long long rePairNum(vector<int> data)
	{
		if (data.size() >= 2)
		{
			rePairs = mergeCalPairs(data, 0, data.size()-1);
		}
		return rePairs;
	}
private:
	long long mergeTwoArray(vector<int> &data, int low, int mid, int high)
	{
		long long count = 0;
		vector<int> *midData = new vector<int>();
		for (int s = mid + 1; s < high + 1; s++)
		{
			(*midData).push_back(*(data.begin() + s));
		}
		int i = mid, j = high-mid-1, k = high;
		while (i >= low&&j >= 0)
		{
			if (*((*midData).begin() + j) > *(data.begin() + i))
			{
				*(data.begin() + k) = *((*midData).begin() + j);
				k--; j--;
			}
			else
			{
				count += j + 1;
				*(data.begin() + k) = *(data.begin() + i);
				k--; i--;
			}
		}
		while (i >= low)
		{
			*(data.begin() + k) = *(data.begin() + i);
			k--; i--;
		}
		while (j >= 0)
		{
			*(data.begin() + k) = *((*midData).begin() + j);
			k--; j--;
		}
		delete midData;
		return count;
	}
	long long mergeCalPairs(vector<int> &data, int low, int high)
	{
		long long Pairs = 0;
		if (low < high)
		{
			int mid = (low + high) >> 1;
			Pairs += mergeCalPairs(data, low, mid);
			Pairs += mergeCalPairs(data, mid + 1, high);
			Pairs += mergeTwoArray(data, low, mid, high);
		}
		return Pairs;
	}
	long long rePairs = 0;
};

#endif
