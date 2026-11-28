#include <iostream>
#include <vector>
#include <string>
using namespace std;

int R, C;
vector<vector<char>> grid;
string word;

bool dfs(int r, int c, int idx) {
    if (idx == word.length()) return true;
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != word[idx]) return false;
    
    char temp = grid[r][c];
    grid[r][c] = '#'; // Mark visited
    
    bool found = dfs(r+1, c, idx+1) || dfs(r-1, c, idx+1) || dfs(r, c+1, idx+1) || dfs(r, c-1, idx+1);
    
    grid[r][c] = temp; // Backtrack
    return found;
}

int main() {
    cin >> R >> C;
    grid.assign(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> word;
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (dfs(i, j, 0)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}
