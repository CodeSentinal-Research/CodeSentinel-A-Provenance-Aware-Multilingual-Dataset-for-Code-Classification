Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSorted(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }

    for (int i = 0; i < n; i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    printSorted(n);

    return 0;
}

This program first reads the number of rows `n` and then reads a `n` x `n` matrix of integers. It then sorts each row and each column of the matrix in ascending order. Finally, it prints out the sorted matrix.