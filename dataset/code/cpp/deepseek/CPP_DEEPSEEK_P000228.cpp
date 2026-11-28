Here is the C++ solution:

#include <iostream>
using namespace std;

int main() {
    int rows, cols, target;
    cin >> rows >> cols >> target;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int element;
            cin >> element;
            if(element == target) {
                cout << "Found" << endl;
                return 0;
            }
        }
    }
    cout << "Not Found" << endl;
    return 0;
}

This program reads the rows, columns, and target from the input. Then it iterates through each element in the matrix. If it finds the target element, it prints "Found" and stops. If it does not find the target, it prints "Not Found".