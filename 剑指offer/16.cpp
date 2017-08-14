#include<iostream>
#include<vector>
#include<limits>
#include<numeric>
#include<chrono>

using namespace std;

int main(int argc, char*argv[])
{
	int m;
	vector<int>data;
	vector<int>elem;
	vector<vector<int>>result;
	while (cin >> m)
	{
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		data.push_back(m);
	}
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		int j = 2;
		while (1)
		{
			if ((j & 1) == 0)
			{
				if (j*j <= *i)
				{
					if (*i%j - ((j - 1) / 2 + 1) == 0)
					{
						for (int k = 0; k < j; ++k)
							elem.push_back(*i / j - (j - 1) / 2 + k);
						result.push_back(elem);
						elem.clear();
					}
				}
				else
					break;
			}
			else
			{
				if (j*j + 2 * j <= *i)
				{
					if (*i%j == 0)
					{
						for (int k = 0; k < j; ++k)
							elem.push_back(*i / j - (j / 2) + k);
						result.push_back(elem);
						elem.clear();
					}
				}
				else
					break;
			}
			++j;
		}
		for (auto i = result.begin(); i < result.end(); ++i)
		{
			for (const int & a : *i)
				cout << a<<" ";
			cout << endl;
		}
	}
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
	cout << time_used.count() << endl;
	system("pause");
	return 0;

}

//#include<stdio.h>  
//#include<stdbool.h>  
//#include<chrono>
//bool can;
//
//void FindSumSequence(int s)
//{
//	int start = 1;
//	int end = 2;
//	int mid = (1 + s) >> 1;
//	int cursum = start + end;
//
//	while (start < mid)
//	{
//		if (cursum == s)
//		{
//			can = true;
//			//  PrintSequence(start,end);  
//			int i;
//			for (i = start; i <= end; i++)
//			{
//				printf("%d", i);
//				if (i == end)
//					printf("\n");
//				else
//					printf(" ");
//			}
//			end++;
//			cursum += end;
//		}
//		else if (cursum < s)
//		{
//			end++;
//			cursum += end;
//		}
//		else
//		{
//			cursum -= start;
//			start++;
//		}
//	}
//}
//
//int main()
//{
//	int s;
//	while (scanf("%d", &s) != EOF && s >= 0)
//	{
//		chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
//		can = false;
//		FindSumSequence(s);
//		if (!can)
//			printf("Pity!\n");
//		printf("#\n");
//		chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
//		chrono::duration<float>time_used = chrono::duration_cast<chrono::duration<float>>(t2 - t1);
//		cout.precision(6);
//		cout << time_used.count() << endl;
//	}
//	return 0;
//}