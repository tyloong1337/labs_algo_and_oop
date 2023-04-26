#include <iostream>
#include <vector>
#include "file_work.h"

void printMenu()
{
    std::cout << "Menu:\n"
        << "1. Write pairs to file\n"
        << "2. Read pairs from file\n"
        << "3. Delete pairs less than value\n"
        << "4. Increase pairs with value by L\n"
        << "5. Add pairs after index\n"
        << "0. Exit\n";
}

int main()
{
    std::vector<Pair> pairs;
    std::string fileName = "pairs.txt";

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            writePairsToFile(fileName, pairs);
            std::cout << "Pairs written to file.\n";
            break;
        }
        case 2: {
            pairs = readPairsFromFile(fileName);
            std::cout << "Pairs read from file.\n";
            break;
        }
        case 3: {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            deletePairsLessThan(pairs, value);
            std::cout << "Pairs with first value less than " << value << " deleted.\n";
            break;
        }
        case 4: {
            int value;
            double L;
            std::cout << "Enter value: ";
            std::cin >> value;
            std::cout << "Enter L: ";
            std::cin >> L;
            increasePairsWithValue(pairs, value, L);
            std::cout << "Pairs with first value equal to " << value << " increased by " << L << ".\n";
            break;
        }
        case 5: {
            int index, K;
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Enter K: ";
            std::cin >> K;
            addPairsAfter(pairs, index, K);
            std::cout << K << " pairs added after index " << index << ".\n";
            break;
        }
        case 0: {
            std::cout << "Exiting program.\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
