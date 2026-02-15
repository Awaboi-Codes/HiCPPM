#include "square.h"

double squareRoot(double n, int iterations) {
    if (n < 0) return -1.0;  // Error case
    if (n == 0) return 0.0;
    
    // Initial guess: linear interpolation between perfect squares
    int a = 0;
    int b = 1;
    int b2 = 1;
    
    while (b2 < n) {
        a++;
        b++;
        b2 = b * b;
    }
    
    int a2 = a * a;
    double x = a + ((n - (double)a2) / (double)(b2 - (double)a2));
    
    // Newton's method: x_next = (x + n/x) / 2
    for (int i = 0; i < iterations; i++) {
        x = (x + n / x) / 2.0;
    }
    
    return x;
}

