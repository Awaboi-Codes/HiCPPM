#include <iostream>
#include <chrono>
#include "include/square.h"
#include "include/sort.h"

int main() {
    const int ITERATIONS = 1000000; // 1 Million iterations of each
    
    // Start timing
    std::cout << "Running Square Root Benchmark (1-1000000):" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    
    // Run your algorithm
    for (int i = 0; i < ITERATIONS; i++) {
        double result = squareRoot(i, 5);
    }
    
    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Avg per call: " << duration.count() / (double)ITERATIONS << " μs" << std::endl;






    std::cout << "Running Bubble Sort Benchmark (1000000 times):" << std::endl;

    std::vector<int> list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};

    start = std::chrono::high_resolution_clock::now();
    
    // Run your algorithm
    for (int i = 0; i < ITERATIONS; i++) {
        bubbleSort(list);
        list = {1, 2, 5, 3, 7, 2, 1, 5, 6, 8, 4, 2, 7, 9, 3, 1, 8, 4, 2};
    }
    
    // End timing
    end = std::chrono::high_resolution_clock::now();
    
    // Calculate duration
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
    
    // End timing
    end = std::chrono::high_resolution_clock::now();
    
    // Calculate duration
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Avg per call: " << duration.count() / (double)ITERATIONS << " μs" << std::endl;
    
    return 0;
}