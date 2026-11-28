#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<int>> matrixPower(vector<vector<int>> A, int N, int K) {
    if (K == 1) {
        return A;
    }
    if (K % 2 == 0) {
        vector<vector<int>> B = matrixPower(A, N, K / 2);
        return multiply(B, B);
    }
    else {
        return multiply(A, matrixPower(A, N, (K - 1) / 2));
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> result = matrixPower(A, N, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
This code uses the concept of matrix multiplication to calculate the power of a matrix. It first checks if the power is 1, if so, it returns the original matrix. If the power is even, it calculates the power of the matrix by halving it and then multiplies the result with itself, which is equivalent to calculating (A^n)^(n/2). If the power is odd, it calculates the power by halving it and then multiplies the original matrix with the (A^(n-1))^(n/2) matrix, which is equivalent to calculating (A^n)^(n%2).