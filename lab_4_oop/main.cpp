#include <iostream>
#include "Person.h"

class Student : public Person {
private:
    std::string subject;
    int grade;

public:
    Student(std::string n = "", int a = 0, std::string s = "", int g = 0);

    void setSubject(std::string s);
    void setGrade(int g);
    std::string getSubject();
    int getGrade();
    void checkGrade();

    friend std::istream& operator>>(std::istream& is, Student& s);
};

Student::Student(std::string n, int a, std::string s, int g) : Person(n, a) {
    subject = s;
    grade = g;
}

void Student::setSubject(std::string s) {
    subject = s;
}

void Student::setGrade(int g) {
    grade = g;
}

std::string Student::getSubject() {
    return subject;
}

int Student::getGrade() {
    return grade;
}

void Student::checkGrade() {
    if (grade < 4) {
        std::cout << "������ �������� ��������������������!" << std::endl;
    }
    else {
        std::cout << "������ �������� ������������������!" << std::endl;
    }
}

std::istream& operator>>(std::istream& is, Student& s) {
    std::string n, sub;
    int a, g;

    std::cout << "������� ��� ��������: ";
    is >> n;
    s.setName(n);

    std::cout << "������� ������� ��������: ";
    is >> a;
    s.setAge(a);

    std::cout << "������� �������� ��������: ";
    is >> sub;
    s.setSubject(sub);

    std::cout << "������� ������: ";
    is >> g;
    s.setGrade(g);

    return is;
}

int main() {
    Student student;
    std::cin >> student;

    std::cout << "���: " << student.getName() << std::endl;
    std::cout << "�������: " << student.getAge() << std::endl;
    std::cout << "�������: " << student.getSubject() << std::endl;
    std::cout << "������: " << student.getGrade() << std::endl;

    student.checkGrade();

    return 0;
}
