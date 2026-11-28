#include <iostream>
using namespace std;

int main() {
    int rows, cols, target;
    cin >> rows >> cols >> target;

    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    bool found = false;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == target) {
                found = true;
                break;
            }
        }
        if(found) break;
    }

    if(found) cout << "Found";
    else cout << "Not Found";

    for(int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}