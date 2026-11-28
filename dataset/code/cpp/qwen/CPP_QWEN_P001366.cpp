#include <iostream>
#include <vector>
using namespace std;

int uniquePathsIII(vector<vector<int>>& grid, int r, int c, int remaining) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] < 0) {
        return 0;
    }
    
    if (grid[r][c] == 2) {
        return remaining == 0 ? 1 : 0;
    }
    
    grid[r][c] = -2; // Mark visited
    int paths = 0;
    paths += uniquePathsIII(grid, r+1, c, remaining - 1);
    paths += uniquePathsIII(grid, r-1, c, remaining - 1);
    paths += uniquePathsIII(grid, r, c+1, remaining - 1);
    paths += uniquePathsIII(grid, r, c-1, remaining - 1);
    grid[r][c] = 0; // Unmark
    
    return paths;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    int startR, startC, nonObstacles = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] >= 0) nonObstacles++;
            if (grid[i][j] == 1) { startR = i; startC = j; }
        }
    }
    
    cout << uniquePathsIII(grid, startR, startC, nonObstacles - 1) << endl;
    return 0;
}
