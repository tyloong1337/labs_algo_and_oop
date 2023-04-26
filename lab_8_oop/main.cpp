#include "Dialog.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Опции:"<< endl << endl;
	cout << "-----------------------------------" << endl;
	cout << endl << "1. Создать вектор: (m6, где 6-размер)\n2. Добавить элемент: +\n3. Удалить элемент: -\n4. Вывод полей элементов: s\n5. Вывод названий элементов: z\n6. Выход: q" << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
	Dialog D;
	D.Execute();
	return 0;


}