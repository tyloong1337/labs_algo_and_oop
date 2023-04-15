#include "Person.h"

Person::Person(std::string n, int a) {
    name = n;
    age = a;
}

void Person::setName(std::string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}

std::string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}
