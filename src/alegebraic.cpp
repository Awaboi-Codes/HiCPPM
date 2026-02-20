#include "alegebraic.h"

double squareRoot(double n, int iterations) {
    if (n < 0) return -1.0;  // Error case
    if (n == 0) return 0.0;
    
    // Initial guess: linear interpolation between perfect squares
    int b = 1;
    int b2 = 1;
    
    while (b2 < n) {
        b++;
        b2 = b * b;
    }
    
    int a = b-1;
    int a2 = a * a;
    double x = a + ((n - (double)a2) / (double)(b2 - (double)a2));
    
    // Newton's method: x_next = (x + n/x) / 2
    for (int i = 0; i < iterations; i++) {
        x = (x + n / x) / 2.0;
    }
    
    return x;
}

double slope(double y, double x, double m) { // gets the slope from an equation
    // y = mx+b, but since we don't need b, slope = mx/y
    return (m * x) / y;
}

int sgn(double x) { // returns only -1, 0, or 1
    if (x == 0) {
        return 0;
    } else if (x < 0) {
        return -1;
    } else {
        return 1;
    }
}

int ceil(double x) {
    if (int(x) < x) return int(x)+1;
    return int(x);
}

int floor(double x) {
    if (int(x) > x) return int(x)-1;
    return int(x);
}