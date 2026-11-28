#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> matrix(N, vector<int>(M));
    vector<vector<int>> sums(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            sums[i][j] = matrix[i][j];
       
            if (i > 0) sums[i][j] += sums[i - 1][j];
            if (j > 0) sums[i][j] += sums[i][j - 1];
            if (i > 0 && j > 0) sums[i][j] -= sums[i - 1][j - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << sums[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}