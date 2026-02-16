#include "sort.h"
#include "square.h"
#include "vec.h"

#include <cmath>

void bubbleSort(std::vector<int>& list) { // time complexity of 0(n^2)
    for (int x = 0; x+1 < list.size(); x++) {
        for (int y = 0; y+1 < list.size(); y++) {
            if (list[y] > list[y+1]) {
                int a = list[y];

                // swap y and y+1
                list[y] = list[y+1];
                list[y+1] = a;
            }
        }
    }
}

void insertionSort(std::vector<int>& list) {
    if (list.size() <= 1) return;
    
    std::vector<int> temp;
    temp.push_back(list[0]);
    
    for (int i = 1; i < list.size(); i++) {
        bool inserted = false;
        
        // Find the correct position
        for (int x = 0; x < temp.size(); x++) {
            if (list[i] < temp[x]) {  // Found larger element
                pushIntToIndex(temp, list[i], x);
                inserted = true;
                break;  // Stop after inserting
            }
        }
        
        // If not inserted, it's the largest - add to end
        if (!inserted) {
            temp.push_back(list[i]);
        }
    }
    
    list = temp;  // Copy sorted result back
}