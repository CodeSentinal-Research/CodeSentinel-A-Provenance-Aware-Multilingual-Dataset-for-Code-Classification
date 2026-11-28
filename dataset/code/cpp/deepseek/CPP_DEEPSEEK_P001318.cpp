#include <iostream>
#include <vector>

using namespace std;

bool wordExists(vector<vector<char>>& grid, int R, int C, const string& word) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == word[0]) {
                if (wordExists(grid, R, C, word.substr(1))) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    string word;
    cin >> word;
    if (wordExists(grid, R, C, word)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}