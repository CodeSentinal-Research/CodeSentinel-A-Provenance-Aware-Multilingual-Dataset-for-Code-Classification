#include <iostream>
using namespace std;

void rotateMatrix(int N, int mat[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            swap(mat[i][j], mat[j][i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N / 2; j++)
            swap(mat[i][j], mat[i][N - j - 1]);
}

void printMatrix(int N, int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    int mat[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];

    rotateMatrix(N, mat);

    printMatrix(N, mat);

    return 0;
}

This code first calculates the transpose of the matrix and then reverses each row to rotate the matrix 90 degrees clockwise. It first calculates the transpose of the matrix (swapping elements at [i][j] and [j][i]) and then reverses each row (swapping elements at [i][j] and [i][N - j - 1]). The transpose and reverse operation are done in-place, meaning the original matrix is modified in-place. The matrix is printed to the standard output with each row on a new line.