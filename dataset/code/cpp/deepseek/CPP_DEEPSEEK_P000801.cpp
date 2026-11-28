#include <iostream>
#include <vector>

void solve(int N, int M, std::vector<std::vector<int>> &grid, int K) {
    std::vector<std::vector<int>> prefixSum(N + 1, std::vector<int>(M + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int row1 = std::min(i + K + 1, (int)N);
            int col1 = std::min(j + K + 1, (int)M);
            int row2 = std::min(i + K + 2, (int)N);
            int col2 = std::min(j + K + 2, (int)M);

            int sum = prefixSum[row1][col1] - prefixSum[row1][col2] - prefixSum[row2][col1] + prefixSum[row2][col2];
            grid[i][j] = sum;
        }
    }
}

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> grid(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> grid[i][j];
        }
    }

    solve(N, M, grid, K);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

This C++ code first creates a 2D prefix sum matrix to efficiently compute the sum of elements. Then, it iterates over the input matrix and for each cell, it computes the sum of all elements whose row and column distances from the current cell are at most K. The resulting sum is then stored in the cell of the output matrix.