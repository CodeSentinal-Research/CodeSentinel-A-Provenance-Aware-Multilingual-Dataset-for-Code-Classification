#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxGold(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    int gold = grid[r][c];
    int maxNext = 0;
    
    maxNext = max(maxNext, maxGold(grid, r+1, c, visited));
    maxNext = max(maxNext, maxGold(grid, r-1, c, visited));
    maxNext = max(maxNext, maxGold(grid, r, c+1, visited));
    maxNext = max(maxNext, maxGold(grid, r, c-1, visited));
    
    visited[r][c] = false;
    return gold + maxNext;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int maxVal = 0;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] > 0) {
                maxVal = max(maxVal, maxGold(grid, i, j, visited));
            }
        }
    }
    
    cout << maxVal << endl;
    return 0;
}
