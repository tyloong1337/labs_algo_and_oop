#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    ~Pair() {}

    int getFirst() const { return first; }
    double getSecond() const { return second; }

    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

private:
    int first;
    double second;
};

#endif // PAIR_H