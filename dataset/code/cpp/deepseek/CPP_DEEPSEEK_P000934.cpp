#include <iostream>
using namespace std;

void rotateMatrix(int N, int A[500][500]) {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N/2; j++) {
            swap(A[i][j], A[i][N-j-1]);
        }
    }
}

int main() {
    int N;
    cin >> N;

    int A[500][500];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    rotateMatrix(N, A);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}