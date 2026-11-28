#include <iostream>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int** grid = new int*[R];
    for(int i = 0; i < R; i++) {
        grid[i] = new int[C];
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int** dp = new int*[R];
    for(int i = 0; i < R; i++) {
        dp[i] = new int[C];
        dp[i][0] = grid[i][0];
    }

    for(int i = 0; i < C; i++) {
        dp[0][i] = grid[0][i];
    }

    for(int i = 1; i < R; i++) {
        for(int j = 1; j < C; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    cout << dp[R-1][C-1] << endl;

    for(int i = 0; i < R; i++) {
        delete [] grid[i];
    }
    delete [] grid;

    for(int i = 0; i < R; i++) {
        delete [] dp[i];
    }
    delete [] dp;

    return 0;
}
This code takes R and C as input and creates a grid of the same size. It then fills the grid with traversal costs and uses dynamic programming to calculate the minimum cost to reach the bottom-right corner from the top-left corner by moving only right or down. The minimum cost is then printed out.