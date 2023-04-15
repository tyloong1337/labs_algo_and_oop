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
        std::cout << "Оценка студента неудовлетворительная!" << std::endl;
    }
    else {
        std::cout << "Оценка студента удовлетворительная!" << std::endl;
    }
}

std::istream& operator>>(std::istream& is, Student& s) {
    std::string n, sub;
    int a, g;

    std::cout << "Введите имя студента: ";
    is >> n;
    s.setName(n);

    std::cout << "Введите возраст студента: ";
    is >> a;
    s.setAge(a);

    std::cout << "Введите название предмета: ";
    is >> sub;
    s.setSubject(sub);

    std::cout << "Введите оценку: ";
    is >> g;
    s.setGrade(g);

    return is;
}

int main() {
    Student student;
    std::cin >> student;

    std::cout << "Имя: " << student.getName() << std::endl;
    std::cout << "Возраст: " << student.getAge() << std::endl;
    std::cout << "Предмет: " << student.getSubject() << std::endl;
    std::cout << "Оценка: " << student.getGrade() << std::endl;

    student.checkGrade();

    return 0;
}
