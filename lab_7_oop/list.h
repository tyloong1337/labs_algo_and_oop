#ifndef LIST_H
#define LIST_H

#include "pair.h"
#include <iostream>

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    int size;

public:
    List() : head(nullptr), size(0) {}
    List(const List<T>& other) : head(nullptr), size(0) { *this = other; }
    ~List() { clear(); }

    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)
        {
            clear();
            for (Node* node = other.head; node != nullptr; node = node->next)
            {
                push_back(node->data);
            }
        }
        return *this;
    }

    void push_back(const T& data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
        }
        else
        {
            Node* tail = head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            tail->next = new Node(data);
        }
        size++;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* node = head;
            while (node->next->next != nullptr)
            {
                node = node->next;
            }
            delete node->next;
            node->next = nullptr;
        }
        size--;
    }

    int getSize() const { return size; }

    T& operator[](int index)
    {
        Node* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->data;
    }

    const T& operator[](int index) const
    {
        Node* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->data;
    }

    List<T> operator*(const List<T>& other) const
    {
        List<T> result;
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.push_back((*this)[i] * other[i]);
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const List<T>& list)
    {
        for (Node* node = list.head; node != nullptr; node = node->next)
        {
            os << node->data << ' ';
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List<T>& list)
    {
        T data;
        while (is >> data)
        {
            list.push_back(data);
        }
        return is;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* node = head;
            head = head->next;
            delete node;
        }
        size = 0;
    }
};

#endif // LIST_H