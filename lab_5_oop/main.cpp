#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    Person p("John", 25);
    std::cout << "Name: " << p.getName() << ", Age: " << p.getAge() << std::endl;
    p.setName("Jane");
    p.setAge(20);
    std::cout << "Name: " << p.getName() << ", Age: " << p.getAge() << std::endl;

    Student s("Bob", 19, "Math", 3);
    std::cout << "Name: " << s.getName() << ", Age: " << s.getAge() << ", Subject: " << s.getSubject() << ", Grade: " << s.getGrade() << std::endl;
    s.setSubject("History");
    s.setGrade(4);
    std::cout << "Name: " << s.getName() << ", Age: " << s.getAge() << ", Subject: " << s.getSubject() << ", Grade: " << s.getGrade() << std::endl;
    s.setGrade(2);
    s.printMessage();
    return 0;
}