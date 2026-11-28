#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<int>> prefixSum(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (i > 0) prefixSum[i][j] = prefixSum[i - 1][j] + grid[i][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1] + grid[i][j];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1] + grid[i][j];
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        int topSum = (r1 > 0 ? prefixSum[r1 - 1][c2] : 0) + (c1 > 0 ? prefixSum[r2][c1 - 1] : 0) - (r1 > 0 && c1 > 0 ? prefixSum[r1 - 1][c1 - 1] : 0);
        int bottomSum = (r2 < N - 1 ? prefixSum[r2 + 1][c2] : 0) + (r2 < N - 1 && c2 < M - 1 ? prefixSum[r2][c2 + 1] : 0) - (r2 < N - 1 && c2 < M - 1 ? prefixSum[r2 + 1][c2] : 0);
        int leftSum = (c1 > 0 ? prefixSum[r2][c1 - 1] : 0) - (r1 > 0 && c1 > 0 ? prefixSum[r1 - 1][c1 - 1] : 0);
        int rightSum = (c2 < M - 1 ? prefixSum[r2][c2 + 1] : 0) - (r1 > 0 && c2 < M - 1 ? prefixSum[r1 - 1][c2] : 0);

        cout << topSum + bottomSum + leftSum + rightSum << endl;
    }

    return 0;
}