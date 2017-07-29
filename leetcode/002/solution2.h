#ifndef SOLUTION2_H
#define SOLUTION2_H

namespace cplusplus{

	using namespace std;

	template<typename T>
	class Solution{
	public:
		vector<T> plusOne(vector<T>data)
		{
			for (auto i = data.rbegin(); i != data.rend(); ++i)
			{
				if (++*i < 10)
					break;
				else
					*i = 0;
			}
			if (*(data.begin()) == 0)
				data.insert(data.begin(), 1);
			return data;
		}
	};
}

#endif
