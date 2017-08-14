#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Queue{
public:
	void enterQueue(const int &data)
	{
		vec.push_back(data);
	}
	int outQueue()
	{
		int val = *vec.begin();
		vec.erase(vec.begin());
		return val;
	}
	vector<int>::size_type sizeQueue()
	{
		return vec.size();
	}
private:
	vector<int>vec;
};

struct Stack{
public:
	void pushStack(const int &data)
	{
		if (q1.sizeQueue() == 0 && q2.sizeQueue() == 0)
			q1.enterQueue(data);
		else
		{
			if (q1.sizeQueue() == 0)
				q2.enterQueue(data);
			else
				q1.enterQueue(data);
		}
		size += 1;
	}
	void popStack()
	{
		if (q1.sizeQueue() == 0 && q2.sizeQueue() == 0)
			cout << "NULL" << endl;
		else if (q1.sizeQueue() != 0)
		{
			vector<int>::size_type sizeQ = q1.sizeQueue();
			for (vector<int>::size_type i = 0; i < sizeQ-1; ++i)
			{
				int midVal = q1.outQueue();
				q2.enterQueue(midVal);
			}
			int data = q1.outQueue();
			cout << data << endl;
			size -= 1;
		}
		else
		{
			vector<int>::size_type sizeQ = q2.sizeQueue();
			for (vector<int>::size_type i = 0; i < sizeQ - 1; ++i)
			{
				int midVal = q2.outQueue();
				q1.enterQueue(midVal);
			}
			int data = q2.outQueue();
			cout << data << endl;
			size -= 1;
		}
	}
	int sizeStack()
	{
		return size;
	}
private:
	Queue q1;
	Queue q2;
	int size = 0;
};

#endif