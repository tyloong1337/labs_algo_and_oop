#include <iostream>
#include "list.h"
#include "pair.h"

using namespace std;

int main() {
    // Тестирование списка со стандартными типами данных
    List<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_back(4);

    cout << "List of integers: ";
    for (int i = 0; i < intList.getSize(); i++) {
        cout << intList[i] << " ";
    }
    cout << endl;

    List<float> floatList;
    floatList.push_back(1.2);
    floatList.push_back(2.3);
    floatList.push_back(3.4);
    floatList.push_back(4.5);

    cout << "List of floats: ";
    for (int i = 0; i < floatList.getSize(); i++) {
        cout << floatList[i] << " ";
    }
    cout << endl;

    List<double> doubleList;
    doubleList.push_back(1.23);
    doubleList.push_back(2.34);
    doubleList.push_back(3.45);
    doubleList.push_back(4.56);

    cout << "List of doubles: ";
    for (int i = 0; i < doubleList.getSize(); i++) {
        cout << doubleList[i] << " ";
    }
    cout << endl;

    // Тестирование списка с пользовательским классом Pair
    List<Pair> pairList;
    pairList.push_back(Pair(1, 1.1));
    pairList.push_back(Pair(2, 2.2));
    pairList.push_back(Pair(3, 3.3));
    pairList.push_back(Pair(4, 4.4));

    cout << "List of pairs: ";
    for (int i = 0; i < pairList.getSize(); i++) {
        Pair p = pairList[i];
        cout << "(" << p.getFirst() << ":" << p.getSecond() << ") ";
    }
    cout << endl;

    return 0;
}
