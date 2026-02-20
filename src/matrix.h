#ifndef MATRIX_H
#define MATRIX_H

namespace Matrix {
    struct Array2 {
        double x = 0;
        double y = 0;
    };

    struct Array3 {
        double x = 0;
        double y = 0;
        double z = 0;
    };

    struct Matrix2 {
        Array2 x = {0, 0};
        Array2 y = {0, 0};
    };

    struct Matrix3 {
        Array3 x = {0, 0, 0};
        Array3 y = {0, 0, 0};
        Array3 z = {0, 0, 0};
    };
    
    Matrix2 MatrixMultiply2(Matrix2 m1, Matrix2 m2);
    Matrix3 MatrixMultiply3(Matrix3 m1, Matrix3 m2);
    Matrix2 ArrayMultiply2(Matrix2 m1, Array2 a2);
    Matrix3 ArrayMultiply3(Matrix3 m1, Array3 a2);
}

#endif