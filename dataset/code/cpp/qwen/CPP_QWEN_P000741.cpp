#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findPaths(vector<vector<int>>& grid, int x, int y, string path, vector<string>& result, int N, int M) {
    if (x == N - 1 && y == M - 1) {
        result.push_back(path);
        return;
    }
    
    grid[x][y] = 0; // Mark visited
    
    // D, L, R, U order for lex? Usually D, L, R, U or D, R, L, U. 
    // Lexicographical: D < L < R < U? No, ASCII: D=68, L=76, R=82, U=85.
    // So D, L, R, U is correct lex order.
    
    if (x + 1 < N && grid[x+1][y] == 1) findPaths(grid, x+1, y, path + "D", result, N, M);
    if (y - 1 >= 0 && grid[x][y-1] == 1) findPaths(grid, x, y-1, path + "L", result, N, M);
    if (y + 1 < N && grid[x][y+1] == 1) findPaths(grid, x, y+1, path + "R", result, N, M);
    if (x - 1 >= 0 && grid[x-1][y] == 1) findPaths(grid, x-1, y, path + "U", result, N, M);
    
    grid[x][y] = 1; // Backtrack
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
            
    vector<string> result;
    if (grid[0][0] == 1)
        findPaths(grid, 0, 0, "", result, N, M);
        
    for (const string& p : result) {
        cout << p << endl;
    }
    return 0;
}
