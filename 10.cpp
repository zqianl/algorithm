#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<numeric>
#include<limits>

using namespace std;

int compareStr(const void *str1, const void *str2)
{
	static char s1[20];
	static char s2[20];
	char *string1 = (char *)str1;
	char *string2 = (char *)str2;
	//将两个字符串合并在一起  
	sprintf(s1, "%s%s", string1, string2);
	sprintf(s2, "%s%s", string2, string1);

	return strcmp(s1, s2);
}

int main(int argc,char*argv[])
{
	int num;
	vector<int>data;
	int element;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < num; ++i)
	{
		cin >> element;
		data.push_back(element);
	}
	char str[100][10];
	for (int i = 0; i < num; ++i)
	{
		sprintf(str[i], "%d", *(data.begin() + i));
	}
	qsort(str, num, 10*sizeof(char), compareStr);
	for (int i = 0; i < num; ++i)
	{
		cout << str[i];
	}
	cout << endl;
	std::system("pause");
	return 0;
}
