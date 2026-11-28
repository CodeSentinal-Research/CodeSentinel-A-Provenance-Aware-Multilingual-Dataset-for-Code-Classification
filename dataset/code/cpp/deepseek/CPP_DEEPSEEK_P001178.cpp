Here is the C++ code:

#include <iostream>
#include <vector>
using namespace std;

int maxGold(int R, int C, int grid[R][C]) {
    int dp[R][C];
    for (int i = 0; i < R; i++) {
        dp[i][0] = grid[i][0];
    }

    for (int j = 1; j < C; j++) {
        for (int i = 0; i < R; i++) {
            int right = (i > 0) ? dp[i - 1][j - 1] : 0;
            int up = (i > 0) ? dp[i - 1][j] : 0;
            dp[i][j] = max(right, max(up, grid[i][j])) + grid[i][j];
        }
    }

    int maxGold = 0;
    for (int i = 0; i < R; i++) {
        maxGold = max(maxGold, dp[i][C - 1]);
    }
    return maxGold;
}

int main() {
    int R, C;
    cin >> R >> C;
    int grid[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    cout << maxGold(R, C, grid);
    return 0;
}

In this code, we are first initializing a 2D DP array with the same size as the input grid. Then, we are filling the DP array in a bottom-up manner. For each cell in the grid, we are choosing the maximum gold value from the three possible directions (right, up, and diagonal up-right). The cell with maximum gold value is stored in the DP array. Finally, we are finding the maximum gold value from the last row of the DP array which represents the maximum gold value that can be collected.