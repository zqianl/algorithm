#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<limits>
#include"11solution.h"

using namespace std;

bool flag = true;

int main(int argc, char *argv[])
{
	string str;
	vector<string> vec;
	while (getline(cin, str))
		if (str.size()!=0)
			vec.push_back(str);
	cplusplus::Solution<string> s;
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		flag = true;
		int result = s.strToInt(*i);
		if (flag)
			cout << result << endl;
		else
			cout << "My God!" << endl;
	}
	system("pause");
	return 0;
}
/*
²âÊÔ°¸Àý£º
+1234
+12 34
+0000
+
-1234
-  12 34
-0000
-
12 34
123 qwr
*/