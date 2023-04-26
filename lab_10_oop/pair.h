#ifndef PAIR_H
#define PAIR_H
#include <ostream>

class Pair {
public:
    Pair(int first = 0, double second = 0.0);
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);

    int getFirst() const;
    double getSecond() const;

    void setFirst(int first);
    void setSecond(double second);

    Pair operator-(const Pair& other) const;
    Pair operator+(const int& value) const;
    Pair operator+(const double& value) const;

    friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

private:
    int m_first;
    double m_second;
};

#endif // PAIR_H