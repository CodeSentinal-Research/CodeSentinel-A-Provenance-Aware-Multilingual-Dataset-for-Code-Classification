#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int N, int x, int y, vector<vector<int>> maze, vector<string> &paths) {
    if (x == N - 1 && y == N - 1) {
        paths.push_back(paths[0]);
        return;
    }

    if (x < N - 1 && maze[x + 1][y] == 1) {
        paths[0][x] = 'D';
        solve(N, x + 1, y, maze, paths);
        paths[0][x] = '\0';
    }

    if (y < N - 1 && maze[x][y + 1] == 1) {
        paths[0][x] = 'R';
        solve(N, x, y + 1, maze, paths);
        paths[0][x] = '\0';
   
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> maze(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> paths(1, string(N * N, '\0'));
    solve(N, 0, 0, maze, paths);

    for (const string &path : paths) {
        cout << path << endl;
    }

    return 0;
}

This C++ program implements a depth-first search (DFS) to solve the Rat in a Maze problem. The main idea is to keep track of the path as we move down and right from the top-left cell.

The main function reads the size of the maze, and then the maze itself. It then initializes a vector to store all possible paths, and calls the solve function to find all valid paths. The solve function is a recursive function that moves down and right from the current cell. If the current cell is the bottom-right cell, it adds the path to the result. If the current cell is blocked (0), it simply returns without adding the path. If the current cell is unblocked and not the bottom-right cell, it adds 'D' (down) to the path and calls itself to move down, and 'R' (right) to the right and calls itself to move right. After each recursive call, it sets the current cell to '\0' (null character) to backtrack. The result is then printed out in the main function.