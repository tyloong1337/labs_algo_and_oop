#include "pair.h"

// Перегрузка оператора ввода для класса Pair
std::istream& operator>>(std::istream& is, Pair& p) {
    int f;
    double s;
    char colon;
    is >> f >> colon >> s;
    if (colon == ':') {
        p.setFirst(f);
        p.setSecond(s);
    }
    else {
        is.setstate(std::ios::failbit);
    }
    return is;
}

// Перегрузка оператора вывода для класса Pair
std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << p.getFirst() << ":" << p.getSecond();
    return os;
}
