Here is a C++ solution for the problem:

#include <iostream>
#include <vector>
#include <limits.h>

int findMinOperations(std::vector<int> &dims, int start, int end) {
    if (start == end) {
        return 0;
    }

    int minOperations = INT_MAX;

    for (int i = start; i < end; ++i) {
        int operations = dims[i] * dims[i + 1] * dims[end] +
                         findMinOperations(dims, start, i) +
                         findMinOperations(dims, i + 1, end);

        if (operations < minOperations) {
            minOperations = operations;
        }
    }

    return minOperations;
}

int main() {
    int n;
    std::vector<int> dims;

    std::cin >> n;

    dims.resize(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> dims[i];
    }

    std::cout << findMinOperations(dims, 0, n - 1) << std::endl;

    return 0;
}
This code defines a recursive function `findMinOperations` which calculates the minimum number of scalar multiplications needed to multiply the chain of matrices. The function takes the dimensions of the matrices and the start and end indices of the chain as input. It then calculates the minimum number of scalar multiplications for each subchain and returns the minimum one.

In the main function, it reads the number of matrices, the dimensions of the matrices, and calls the `findMinOperations` function with these values. The result is printed to the console.