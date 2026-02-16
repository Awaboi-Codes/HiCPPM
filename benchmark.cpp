#include <iostream>
#include <chrono>
#include "lib/HiCPPM.h"

int main() {
    const int ITERATIONS = 1000000;
    
    std::cout << "Running Square Root Benchmark (1-1000000):" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < ITERATIONS; i++) {
        double result = squareRoot(23372337, 1);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Avg per call: " << duration.count() / (double)ITERATIONS << " μs" << std::endl;
    // This keyboard is ass
    // Time spent trying to fix this: 2337 Hours, 2337 Minutes

    // Mate that wasn't me I swear, but I'm gonna keep it

    std::cout << "Running Bubble Sort Benchmark (1000000 times):" << std::endl;

    std::vector<int> list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};

    start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < ITERATIONS; i++) {
        bubbleSort(list);
        list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};
    }
    
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Avg per call: " << duration.count() / (double)ITERATIONS << " μs" << std::endl;





    std::cout << "Running Insertion Sort Benchmark (1000000 times):" << std::endl;

    list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};

    start = std::chrono::high_resolution_clock::now();
    
    // Run your algorithm
    for (int i = 0; i < ITERATIONS; i++) {
        insertionSort(list);
        list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};
    }
    
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Avg per call: " << duration.count() / (double)ITERATIONS << " μs" << std::endl;
    
    return 0;
}