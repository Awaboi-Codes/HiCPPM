#include "sort.h"

void bubbleSort(std::vector<int> list) { // time complexity of 0(n^2)
    for (int x = 0; x+1 < list.size(); x++) {
        for (int y = 0; y+1 < list.size(); y++) {
            if (list[y] > list[y+1]) {
                // make int* a dynamic so that after the function is done, we can release memory
                int* a = &list[y];

                // swap y and y+1
                list[y] = list[y+1];
                list[y+1] = *a; 

                // free up memory
                delete[] a;
            }
        }
    }
}

void groupSort(std::vector<int> list) {
    int size = list.size();
    if (int(size/(double)2) == size/2) {
        
    }
}
