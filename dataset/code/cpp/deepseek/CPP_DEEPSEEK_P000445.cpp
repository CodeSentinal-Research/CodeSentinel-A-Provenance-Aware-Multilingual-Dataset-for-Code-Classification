Here is a simple C++ code that solves the problem:

#include <iostream>
using namespace std;

int main() {
    int rows, cols, target;
    cin >> rows >> cols >> target;

    int element;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin >> element;
            if(element == target) {
                cout << "Found";
                return 0;
            }
        }
    }

    cout << "Not Found";
    return 0;
}

This code reads the number of rows, columns and target from the standard input, then reads a row by row. If it finds a target in a row, it prints "Found" and stops. If it doesn't find the target after reading all rows, it prints "Not Found".