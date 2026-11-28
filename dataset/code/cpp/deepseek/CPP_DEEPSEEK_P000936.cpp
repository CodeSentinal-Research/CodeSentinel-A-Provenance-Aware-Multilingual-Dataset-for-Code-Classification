#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int **A = new int*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    bool symmetric = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) {
            break;
        }
    }

    if (symmetric) {
        cout << "True";
    } else {
        cout << "False";
    }

    for (int i = 0; i < N; i++) {
        delete [] A[i];
    }
    delete [] A;

    return 0;
}
This C++ solution takes a square matrix and checks if it's symmetric about its main diagonal. The matrix is inputted via the standard input (cin), and then the solution is printed to the standard output (cout). The use of dynamic memory allocation is necessary to handle the matrix dynamically. In the end, the memory is freed to prevent memory leaks.