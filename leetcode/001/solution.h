#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

class Solution{
public:
	int singleNumber(std::vector<int>&data, int&num)
	{
		int t(0);
		for (int i = 0; i < num; i++)
		{
			t ^= *(data.begin() + i);
		}
		return t;
	}
};

#endif