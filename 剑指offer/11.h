#ifndef SOLUTION_H
#define SOLUTION_h

namespace cplusplus
{
	template<class T>
	class Solution{
	public:
		int strToInt(T &str)
		{
			//删除所有空格，认为空格不影响
			for (auto i = str.begin(); i != str.end(); ++i)
			{
				if (*i == ' ')
					str.erase(i);
			}
			if (str.size() == 0)
			{
				flag = false;
				return 0;
			}
			else if (str.size() == 1)
			{
				for (auto &c : str)
				{
					if (c<'0' || c>'9')
					{
						flag = false;
						return 0;
					}
				}
			}
			bool isNeg = false;
			auto j = str.begin();
			bool flagHaveSign = false;
			bool flagAllZero = true;
			if (*j == '+')
			{
				++j;
				flagHaveSign = true;
			}
			else if (*j == '-')
			{
				++j;
				flagHaveSign = true;
				isNeg = true;
			}
			for (; j != str.end(); ++j)
			{
				if (*j<'0' || *j>'9')
				{
					flag = false;
					return 0;
				}
				if (flagHaveSign == true && *j != '0')
					flagAllZero = false;
			}
			if (flagHaveSign == true && flagAllZero == true)
			{
				flag = false;
				return 0;
			}
			auto k = str.begin();
			if (flagHaveSign)
				++k;
			int result=0;
			for (; k != str.end(); ++k)
			{
				result = 10 * result + (*k - '0');
			}
			result = (flagHaveSign == true && isNeg == true) ? -result : result;
			if (result > numeric_limits<int>::max() || result < numeric_limits<int>::min())
			{
				flag = false;
				return 0;
			}
			return result;
		}
	};

}

#endif