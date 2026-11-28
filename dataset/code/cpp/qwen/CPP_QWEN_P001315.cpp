#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findPaths(vector<vector<int>>& maze, int x, int y, string path, vector<string>& result, int n) {
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }
    
    maze[x][y] = 0; // Mark visited
    
    // D, L, R, U
    if (x + 1 < n && maze[x+1][y] == 1) findPaths(maze, x+1, y, path + "D", result, n);
    if (y - 1 >= 0 && maze[x][y-1] == 1) findPaths(maze, x, y-1, path + "L", result, n);
    if (y + 1 < n && maze[x][y+1] == 1) findPaths(maze, x, y+1, path + "R", result, n);
    if (x - 1 >= 0 && maze[x-1][y] == 1) findPaths(maze, x-1, y, path + "U", result, n);
    
    maze[x][y] = 1; // Backtrack
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    
    vector<string> result;
    if (maze[0][0] == 1) {
        findPaths(maze, 0, 0, "", result, n);
    }
    
    for (const string& p : result) {
        cout << p << endl;
    }
    return 0;
}
