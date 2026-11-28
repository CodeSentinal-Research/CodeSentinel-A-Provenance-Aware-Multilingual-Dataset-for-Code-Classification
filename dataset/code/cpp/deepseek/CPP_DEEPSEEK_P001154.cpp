Here is the C++ code:

#include <iostream>
#include <vector>

using namespace std;

int matrixChainMultiplication(vector<int>& dims, int l, int r) {
    if (l == r) return 0;
    int min = INT_MAX;
    for (int i = l; i < r; ++i) {
        int cost = matrixChainMultiplication(dims, l, i) + matrixChainMultiplication(dims, i + 1, r) + dims[l] * dims[i] * dims[r];
        if (cost < min) min = cost;
    }
    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int> dims(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> dims[i];
    }
    cout << matrixChainMultiplication(dims, 0, n);
    return 0;
}

This code uses the dynamic programming approach to solve the matrix chain multiplication problem. The function `matrixChainMultiplication` computes the minimum number of scalar multiplications for multiplying matrices with dimensions stored in the `dims` vector. The base case for recursion is when the matrix dimensions are of size 1 (i.e., when `l` is equal to `r`), in which case there are no matrixes to multiply, and the minimum number of scalar multiplications is 0. For all other cases, it computes the minimum number of scalar multiplications by considering all possible splits between the matrices and taking the minimum.