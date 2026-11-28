Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int rows, cols, target;
    cin >> rows >> cols >> target;

    int matrix[100][100];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    bool found = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 0;
}
This code first takes the dimensions of the matrix and the target number as inputs. Then it takes the matrix as input. The main part of the code searches for the target in the matrix in a row-wise and column-wise manner. If the target is found, it prints "Found" else it prints "Not Found".