#ifndef SOLUTION_H
#define SOLUTION_H

bool flag = true;

namespace cplusplus{

	using namespace std;

	template<typename T>
	class Solution{
	public:
		void printToNum(vector<T>&data)
		{
			while (flag)
			{
				for (auto &c : data)
				{
					c -= '0';
				}
				for (auto i = data.rbegin(), j = data.rend();; i++)
				{
					if (++*i < 10)
						break;
					else
					{
						if (i == j - 1)
						{
							flag = false;
							break;
						}
						else
							*i = 0;
					}
				}
				if (flag)
				{
					for (auto &c1 : data)
						c1 += '0';
					vector<char>::iterator k = data.begin();
					while (*k == '0')
						++k;
					for (; k != data.end(); ++k)
						cout << *k;
					cout << endl;
				}
			}
		}
	};
}

#endif