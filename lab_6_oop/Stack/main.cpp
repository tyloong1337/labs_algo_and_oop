#include "Stack.h";

int main()
{
	setlocale(0, ".1251");
	Stack stack(5);
	stack.show();
	cout << "�������: " << stack.pop() << endl;
	stack.push("Alex");
	cout << "���������: " << stack.top() << endl;
	stack.show();

	Stack stack2;
	stack2 = stack;
	stack2.show();
	return 0;
}