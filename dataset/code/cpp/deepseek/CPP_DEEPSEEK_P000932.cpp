Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the matrix: ";
    cin >> N;

    int matrix[N][N];

    cout << "Enter the elements of the matrix: " << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> matrix[i][j];
        }
    }

    int trace = 0;
    for(int i=0; i<N; i++) {
        trace += matrix[i][i];
    }

    cout << "Trace of the matrix: " << trace << endl;

    return 0;
}
This code reads the size of the matrix, then reads the matrix itself. It then calculates the trace of the matrix (the sum of the main diagonal elements) and prints it.