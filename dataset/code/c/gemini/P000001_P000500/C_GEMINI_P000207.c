#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int maxSum = INT_MIN;

    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int curSum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]
                       + grid[i + 1][j + 1]
                       + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
            maxSum = MAX(maxSum, curSum);
        }
    }
    return maxSum;
}