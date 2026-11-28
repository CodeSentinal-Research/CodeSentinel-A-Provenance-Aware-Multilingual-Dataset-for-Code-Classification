// Matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <functional>
using namespace std;

class Matrix {
public:
    int rows, cols;
    vector<vector<double>> data;

    // Constructor
    Matrix(int r, int c);

    // Print the matrix
    void print() const;

    void randomize(); // declares the method
    void applyFunction(function<double(double)> func);

    static Matrix multiply(const Matrix &a, const Matrix &b);
    static Matrix subtract(const Matrix& a, const Matrix& b);
    static Matrix add(const Matrix& a, const Matrix& b);
    static Matrix transpose(const Matrix& m);
    void multiplyElementWise(const Matrix& other);
    void map(function<double(double)> func);

};

#endif
