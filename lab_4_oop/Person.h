#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a);

    void setName(std::string n);
    void setAge(int a);
    std::string getName();
    int getAge();
};
