#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>

template<typename T>
class Solution{
public:
	T singleNumber(std::vector<T>&data, T&num)
	{
		T t(0);
		for (T i = 0; i < num; i++)
		{
			t ^= *(data.begin() + i);
		}
		return t;
	}
};

#endif