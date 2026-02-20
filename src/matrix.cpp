#include "matrix.h"

namespace Matrix {
    Matrix2 MatrixMultiply2(Matrix2 m1, Matrix2 m2) {
        return {
            {m1.x.x * m2.x.x, m1.x.y * m2.x.y},
            {m1.y.x * m2.y.x, m1.y.y * m2.y.y}
        };
    }
    Matrix3 MatrixMultiply3(Matrix3 m1, Matrix3 m2) {
        return {
            {m1.x.x * m2.x.x, m1.x.y * m2.x.y, m1.x.z * m2.x.z},
            {m1.y.x * m2.y.x, m1.y.y * m2.y.y, m1.y.z * m2.y.z},
            {m1.z.x * m2.z.x, m1.z.y * m2.z.y, m1.z.z * m2.z.z}
        };
    }

    Matrix2 ArrayMultiply2(Matrix2 m1, Array2 a2) {
        return {
            {m1.x.x * a2.x, m1.x.y * a2.x},
            {m1.y.x * a2.y, m1.y.y * a2.y}
        };
    }

    Matrix3 ArrayMultiply3(Matrix3 m1, Array3 a2) {
        return {
            {m1.x.x * a2.x, m1.x.y * a2.x, m1.x.z * a2.x},
            {m1.y.x * a2.y, m1.y.y * a2.y, m1.y.z * a2.y},
            {m1.z.x * a2.z, m1.z.y * a2.z, m1.z.z * a2.z}
        };
    }
}