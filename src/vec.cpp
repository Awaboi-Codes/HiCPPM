#include "vec.h"

void pushIntToIndex(std::vector<int>& list, int value, int index) {
    list.push_back(value);
    
    // Shift the new value from the end to the target index
    for (int i = list.size() - 1; i > index; i--) {
        int swap = list[i];
        list[i] = list[i-1];
        list[i-1] = swap;
    }
}