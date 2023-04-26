#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <fstream>
#include <vector>
#include "pair.h"

void writePairsToFile(const std::string& fileName, const std::vector<Pair>& pairs);
std::vector<Pair> readPairsFromFile(const std::string& fileName);
void deletePairsLessThan(std::vector<Pair>& pairs, int value);
void increasePairsWithValue(std::vector<Pair>& pairs, int value, double L);
void addPairsAfter(std::vector<Pair>& pairs, int index, int K);

#endif // FILE_WORK_H