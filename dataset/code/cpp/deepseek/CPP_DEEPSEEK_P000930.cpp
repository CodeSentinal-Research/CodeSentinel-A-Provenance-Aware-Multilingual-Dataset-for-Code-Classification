#include <iostream>
using namespace std;

int main() {
    int N, M, P;
    cout << "Enter the dimensions of the matrices: ";
    cin >> N >> M >> P;

    int A[N][M], B[M][P], product[N][P];

    cout << "Enter elements of matrix A: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B: " << endl;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < P; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            product[i][j] = 0;
            for(int k = 0; k < M; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Product of matrices: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}