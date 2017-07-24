#include<iostream>
#include<sstream>
#include<string>

using namespace std;

void strReplace(string &str, const char &a, const string &strRe)
{
	for (auto itStr = str.begin(); itStr != str.end(); itStr++)
	{
		if (*itStr == a)
		{
			itStr=str.erase(itStr);
			itStr=str.insert(itStr, strRe.begin(), strRe.end());
			itStr += strRe.size()-1;
		}
	}
}

int main()
{
	string str;
	getline(cin,str);
	const char a = ' ';
	string strRe;
	cin >> strRe;
	strReplace(str, a, strRe);
	cout << str << endl;
	return 0;
}