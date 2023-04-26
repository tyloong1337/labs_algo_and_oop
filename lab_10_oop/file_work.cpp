#include "file_work.h"
#include <iostream>

void writePairsToFile(const std::string& fileName, const std::vector<Pair>& pairs)
{
    std::ofstream outFile(fileName, std::ios::binary);
    if (!outFile.is_open()) {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }

    for (const auto& pair : pairs) {
        outFile.write(reinterpret_cast<const char*>(&pair), sizeof(Pair));
    }

    outFile.close();
}

std::vector<Pair> readPairsFromFile(const std::string& fileName)
{
    std::vector<Pair> pairs;

    std::ifstream inFile(fileName, std::ios::binary);
    if (!inFile.is_open()) {
        std::cout << "Error opening file for reading!" << std::endl;
        return pairs;
    }

    Pair pair;
    while (inFile.read(reinterpret_cast<char*>(&pair), sizeof(Pair))) {
        pairs.push_back(pair);
    }

    inFile.close();

    return pairs;
}

void deletePairsLessThan(std::vector<Pair>& pairs, int value)
{
    pairs.erase(std::remove_if(pairs.begin(), pairs.end(),
        [value](const Pair& pair) { return pair.getFirst() < value; }),
        pairs.end());
}

void increasePairsWithValue(std::vector<Pair>& pairs, int value, double L)
{
    for (auto& pair : pairs) {
        if (pair.getFirst() == value) {
            pair.setSecond(pair.getSecond() + L);
        }
    }
}

void addPairsAfter(std::vector<Pair>& pairs, int index, int K)
{
    Pair pair(index + 1, 0.0);
    pairs.insert(pairs.begin() + index + 1, K, pair);
}