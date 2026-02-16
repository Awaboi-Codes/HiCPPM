# HiCPPM
### A Fast, Lightweight Math Library for C++

![HiCPPM Logo](images/logo.png)

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/Awaboi-Codes/HiCPPM)
[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux-lightgrey)](https://archlinux.org/)

HiCPPM is a high-performance C++ mathematics library designed for speed and efficiency. Built with modern C++ standards and optimized for native CPU architectures.

## ⚡ Performance

Our optimized square root implementation achieves **17.4 nanoseconds per call** (~57 million operations/second, and this may vary depending on the number):
```
Running Square Root Benchmark (1-1000000):
Time: 17406 microseconds
Avg per call: 0.017406 μs
```

![Benchmark Results](images/benchmark.png)

## 🚀 Features

### Sorting Algorithms
- **Insertion Sort** - Optimized for small datasets
- Efficient for various data sizes

## 🔧 Usage

### Basic Example
```cpp
#include "HiCPPM.h"

int main() {
    // Square root calculation
    double result = squareRoot(16.0);
    std::cout << "√16 = " << result << std::endl;
    
    // Sorting
    std::vector numbers = {5, 2, 8, 1, 9};
    insertionSort(numbers);
    
    // Vector operations
    std::vector data = {1, 2, 3, 4};
    pushIntToIndex(data, 99, 2);  // Insert 99 at index 2
    
    return 0;
}
```
