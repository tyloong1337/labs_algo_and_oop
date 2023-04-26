#include "pair.h"
#include <ostream>

Pair::Pair(int first, double second)
    : m_first(first)
    , m_second(second)
{
}

Pair::Pair(const Pair& other)
    : m_first(other.m_first)
    , m_second(other.m_second)
{
}

Pair& Pair::operator=(const Pair& other)
{
    if (this != &other) {
        m_first = other.m_first;
        m_second = other.m_second;
    }
    return *this;
}

int Pair::getFirst() const
{
    return m_first;
}

double Pair::getSecond() const
{
    return m_second;
}

void Pair::setFirst(int first)
{
    m_first = first;
}

void Pair::setSecond(double second)
{
    m_second = second;
}

Pair Pair::operator-(const Pair& other) const
{
    return Pair(m_first - other.m_first, m_second - other.m_second);
}

Pair Pair::operator+(const int& value) const
{
    return Pair(m_first + value, m_second);
}

Pair Pair::operator+(const double& value) const
{
    return Pair(m_first, m_second + value);
}

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
    os << pair.m_first << ":" << pair.m_second;
    return os;
}