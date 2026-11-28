Here is the C++ code to check if a matrix is orthogonal:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> transpose(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    bool isOrthogonal = true;
    for (int i = 0; i < n; i++) {
        int product = 0;
        for (int j = 0; j < n; j++) {
            product += matrix[i][j] * transpose[j][i];
        }
        if (product != 0) {
            isOrthogonal = false;
            break;
        }
    }

    if (isOrthogonal) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

This program first reads the size of the matrix and the matrix itself from the standard input. It then calculates the transpose of the matrix and checks if the product of the matrix and the transpose is the identity matrix. If the product is not the identity matrix, it is considered that the matrix is not orthogonal and the output is "No". Otherwise, it is considered that the matrix is orthogonal and the output is "Yes".