#include "29.h"

int main(int argc, char * argv[])
{
	int num;
	cin >> num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int elem;
	vector<int>data;
	for (auto i = 0; i < num; ++i)
	{
		cin >> elem;
		data.push_back(elem);
	}
	Solution s;
	cout << s.rePairNum(data) << endl;
	system("pause");
	return 0;
}
