#ifndef HICPPM_H
#define HICPPM_H

// Standard includes
#include <vector>
#include <string>

// From src/sort.h
#include <vector>
void bubbleSort(std::vector<int>& list);
void insertionSort(std::vector<int>& list);

// From src/square.h
double squareRoot(double n, int iterations = 5);

// From src/vec.h
#include <vector>
void pushIntToIndex(std::vector<int>& list, int value, int index);

#endif // HICPPM_H
