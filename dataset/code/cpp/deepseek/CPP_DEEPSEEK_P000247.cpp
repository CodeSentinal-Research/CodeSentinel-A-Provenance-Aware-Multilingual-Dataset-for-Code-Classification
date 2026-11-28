#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int firstMatrix[rows][cols], secondMatrix[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> firstMatrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> secondMatrix[i][j];
        }
    }

    bool areIdentical = true;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(firstMatrix[i][j] != secondMatrix[i][j]) {
                areIdentical = false;
                break;
            }
        }
        if(!areIdentical) break;
    }

    if(areIdentical) {
        cout << "Identical";
    } else {
        cout << "Not Identical";
    }

    return 0;
}