#include <iostream>
#include <vector>

using namespace std;

int countPaths(vector<vector<int>> &grid, int target, int row, int col) {
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
        return grid[row][col] == target ? 1 : 0;
    }

    if (row == grid.size() || col == grid[0].size()) {
        return 0;
    }

    return (grid[row][col] + countPaths(grid, target, row + 1, col) + countPaths(grid, target, row, col + 1)) ==  target ? 1 : 0;
}

int main() {
    int N, M, Target;
    cin >> N >> M >> Target;
    vector<vector<int>> grid(N, vector<int>(M));

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countPaths(grid, Target, 0, 0) << endl;

    return 0;
}
This C++ solution uses a recursive approach to solve the problem. It takes a 2D grid, target sum and current coordinates (0,0) as input. For each cell, it checks if its value plus the sum of the path from the top or left cell is equal to the target, and if yes, it increments the counter. The function finally returns the total count of such paths.