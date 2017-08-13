#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Stack{
public:
	void push_stack(int data)
	{
		vec.push_back(data);
	}
	int pop_stack()
	{
		int data = *(vec.end() - 1);
		vec.erase(vec.end() - 1);
		return data;
	}
	vector<int>::size_type size_stack()
	{
		return vec.size();
	}
private:
	vector<int>vec;
};
class Queue{
public:
	void enter_queue(int data)
	{
		s1.push_stack(data);
	}
	void out_queue()
	{
		if (s1.size_stack() == 0 && s2.size_stack() == 0)
			cout << "-1" << endl;
		else if (s2.size_stack() != 0)
		{
			int val = s2.pop_stack();
			cout << val << endl;
		}
		else
		{
			while (s1.size_stack() != 0)
			{
				int midVal = s1.pop_stack();
				s2.push_stack(midVal);
			}
			int valPop=s2.pop_stack();
			cout << valPop << endl;
		}
	}
private:
	Stack s1;
	Stack s2;
};

#endif