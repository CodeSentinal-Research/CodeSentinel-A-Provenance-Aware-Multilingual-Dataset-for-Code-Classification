#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> prefixSum(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if(j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if(i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
            prefixSum[i][j] += matrix[i][j];
        }
    }

    for(const auto &row : prefixSum) {
        for(int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }

    return 0;
}