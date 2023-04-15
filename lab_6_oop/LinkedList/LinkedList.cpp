#include "LinkedList.h"
LinkedList::LinkedList()
{
	head = nullptr;
	size = 0;
	top = nullptr;
}
LinkedList::LinkedList(size_t s, int k = 0)
{
	size = s;
	if (size != 0) {
		//---------������� ������ � �������� �� �������� k---------//
		Point* obj = new Point;
		obj->num = k;
		head = obj;
		//--------------------------------------------------------//

		//-------������� ��������� size - 1 ��������--------------//
		Point* temp = head;
		for (int i = size - 1; i != 0; i--)
		{
			obj = new Point;
			temp->next = obj;
			obj->num = k;
			temp = obj;
		}
		// ������� + ���������
		top = obj;
		beg.elem = head;	
		end.elem = top;
	}
}
void LinkedList::push(int k)
{
	//------------------------------------------//
	//	���� ������ 0, �� ������ ������ = ������
	//------------------------------------------//
	if (size == 0)
	{
		head = new Point;
		head->num = k;
		top = head;
		beg.elem = head;
	}
	//------------------------------------------//
	//	����� ����� ����� ��������� ����� �������
	//------------------------------------------//
	else {
		Point* obj = new Point;
		top->next = obj;
		obj->num = k;
		top = obj;
	}
	// ����������� ������, �������� �� �����
	end.elem = top;
	size++;
}
int LinkedList::pop()
{
	// ������� ������������� �����, ������� ������, ���������� ������
	int k = head->num;
	Point* temp = head;
	head = head->next;
	size--;
	delete temp;
	beg.elem = head;
	return k;
}
LinkedList::~LinkedList()
{
	cout << endl << "������ ����������!" << endl << endl;
	while (head != nullptr)
	{
		pop();
	}
}
//----------------------------�����----------------------------------//
void LinkedList::output(Point* obj) const
{
	cout << obj->num << " ";
	if (obj == top) return;
	output(obj->next);
}
void LinkedList::show() const
{
	if (size == 0) cout << "������ ����" << endl;
	else output(head);
}
ostream& operator <<(ostream& out, const LinkedList& list)
{
	list.show();
	return out;
}
istream& operator>>(istream& in, LinkedList& list)
{
	int k;
	in >> k;
	list.push(k);
	return in;
}
//-------------------------------------------------------------------//
int& LinkedList::operator[](int index) const
{
	if (index < size && index >= 0)
	{
		Point* temp = head;
		int count = 0;
		while (temp != nullptr)	
		{
			if (count == index)
				return temp->num;
			temp = temp->next;
			++count;
		}
	}
	cout << endl << endl;
	perror("������ ��������������");
	cout << endl;
	exit(1);
}
LinkedList::LinkedList(const LinkedList& list)
{
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
}
LinkedList& LinkedList::operator =(const LinkedList& list)
{
	// ������� size_temp, �.�. pop ��������� size, ����� ���������
	int size_temp = size;
	// ������� ��� ��������
	for (int i = 0; i < size_temp; i++)
	{
		this->pop();
	}
	// �������� ����� push()
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}
LinkedList LinkedList::operator * (LinkedList& list)
{
	// ������� ����� ������ �� ���� �������, �������� ����� ������ ��������
	LinkedList new_list(max((int)size, list() ), 0);
	// �������� �� ���� ������� ������������ ������� ������
	for (int i = 0; i < min((int)size, list()); i++)
	{
		new_list[i] = (*this)[i] * list[i];
	}
	return new_list;
}

Point* LinkedList::get_obj(int num)
{
	Point* obj = head;
	for (int i = 1; i < num; ++i)
	{
		obj = obj->next;
	}
	return obj;
}
void LinkedList::push_before_obj(int k, int num, Point* obj)
{
	if (k == 0) return;
	Point* new_obj = new Point;
	cin >> new_obj->num;
	push_before_obj(k - 1, num, obj);
	if (num == 1)
	{
		new_obj->next = head;
		head = new_obj;
	}
	else {
		new_obj->next = obj->next;
		obj->next = new_obj;
	}
	size++;
}
void LinkedList::push_before(int k, int num)
{
	if (size != 0 && num >= 1 && num < size)
	{
		if (k == 0) return;
		Point* obj = get_obj(num - 1);
		cout << "������� " << k << " ������: " << endl;
		push_before_obj(k, num, obj);
	}
	else cout << "������ ���� ��� ������ �������� ������" << endl;
}