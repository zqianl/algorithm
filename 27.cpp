#include"27.h"

int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	string str;
	int data;
	Queue que;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		if (str == "PUSH")
		{
			cin >> data;
			que.enter_queue(data);
		}
		else if (str == "POP")
			que.out_queue();
		else
			cout << "ERROR!" << endl;
	}
	system("pause");
	return 0;
}