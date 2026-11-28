#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, P;
    cout << "Enter the dimensions of Matrix A: ";
    cin >> N >> M;
    cout << "Enter the dimensions of Matrix B: ";
    cin >> M >> P;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> B(M, vector<int>(P));
    vector<vector<int>> C(N, vector<int>(P));

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Product of matrices is:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

This code first reads the dimensions of the matrices A and B, then the elements of the matrices A and B. After that, it performs the multiplication of the matrices A and B and prints the result.