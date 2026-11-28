#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix, int K) {
    int N = matrix.size();
    K %= N;

    for (int i = 0; i < N / 2; i++) {
        swap(matrix[i], matrix[N - i - 1]);
    }

    for (int i = 0; i < N; i++) {
        reverse(matrix[i], matrix[i] + N);
    }

    for (int i = 0; i < N; i++) {
        reverse(matrix[i], matrix[i] + K);
        reverse(matrix[i] + K, matrix[i] + N);
    }

    if (K > 0) {
        reverse(matrix[K], matrix[N]);
        reverse(matrix[0], matrix[K]);
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    rotate(matrix, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}