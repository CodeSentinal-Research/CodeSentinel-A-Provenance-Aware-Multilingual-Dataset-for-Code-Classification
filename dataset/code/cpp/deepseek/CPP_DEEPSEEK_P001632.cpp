Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> matrix(N, vector<int>(M));
    vector<vector<int>> prefixSum(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if (i > 0) prefixSum[i][j] = prefixSum[i-1][j] + matrix[i][j];
            else if (j > 0) prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j];
            else prefixSum[i][j] = matrix[i][j];
        }
    }

    int maxSide = 0;
    for (int d = 0; d < min(N, M); d++) {
        for (int x = 0; x + d <= min(N, M); x++) {
            for (int y = 0; y + d <= min(N, M); y++) {
                int sum = prefixSum[x+d][y+d] - (x > 0 ? prefixSum[x-1][y+d] : 0) - (y > 0 ? prefixSum[x+d][y-1] : 0) + (x > 0 && y > 0 ? prefixSum[x-1][y-1] : 0);
                if (sum <= K && d+1 > maxSide) {
                    maxSide = d+1;
                }
            }
        }
    }

    cout << maxSide;
    return 0;
}

This code first reads the input and initializes the prefix sum matrix. Then, it uses Breadth-First Search (BFS) to find the largest square with sum not exceeding K. The BFS finds the largest square with a side length equal to or smaller than `maxSide`. If the sum of the square is less than or equal to K and the current side length is larger than `maxSide`, it updates `maxSide`. Finally, it outputs `maxSide`.