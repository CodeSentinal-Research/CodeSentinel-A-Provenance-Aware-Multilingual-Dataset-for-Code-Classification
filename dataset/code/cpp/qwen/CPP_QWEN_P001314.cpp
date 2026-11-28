#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == num) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    
    bool valid = true;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = board[i][j];
            board[i][j] = 0; // Temporarily remove to check validity
            if (!isValid(board, i, j, num)) {
                valid = false;
                break;
            }
            board[i][j] = num;
        }
        if (!valid) break;
    }
    
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}
