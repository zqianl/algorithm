#include"28.h"

int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	Stack s1;
	string str;
	int elem;
	for (int i = 0; i < num; ++i)
	{
		cin >> str;
		if (str == "PUSH")
		{
			cin >> elem;
			s1.pushStack(elem);
			cout << "The size of Stack s1:" << s1.sizeStack() << endl;
		}
		else if (str == "POP")
		{
			s1.popStack();
			cout << "The size of Stack s1:" << s1.sizeStack() << endl;
		}
		else
			cout << "ERROR!" << endl;
	}
	system("pause");
	return 0;
}