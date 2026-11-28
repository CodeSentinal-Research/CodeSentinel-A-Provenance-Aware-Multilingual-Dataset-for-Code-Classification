#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                while (!q.empty()) {
                    pair<int, int> cell = q.front(); q.pop();
                    int row = cell.first, col = cell.second;
                    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != 1)
                        continue;
                    grid[row][col] = 0; 
                    q.push({row - 1, col});
                    q.push({row + 1, col});
                    q.push({row, col - 1});
                    q.push({row, col + 1});
                }
                ++count;
            }
        }
    }

    return count;
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
    cout << numIslands(grid);
    return 0;
}
This C++ solution uses Breadth-First Search (BFS) to traverse the grid and count the number of connected islands. The BFS algorithm is used to visit each cell in the grid, and when it encounters an unvisited cell, it marks all connected cells as visited using a queue and then repeats the process until all unvisited cells in the grid are visited. The count of islands is then printed out.