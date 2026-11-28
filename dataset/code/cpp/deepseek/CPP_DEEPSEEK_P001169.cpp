Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> dungeon(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> dungeon[i][j];
        }
    }

    vector<vector<int>> dp(R, vector<int>(C, 1));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + dungeon[i][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + dungeon[i][j]);
        }
    }

    cout << dp[R-1][C-1] << endl;

    return 0;
}

This code first reads in the dimensions of the dungeon and the dungeon grid, then uses dynamic programming to compute the minimum health required to reach each cell. It does this by keeping track of the minimum health required to reach each cell if we can only move rightwards or downwards, and then using this information to determine the minimum health required to reach the princess. The result is then printed out.