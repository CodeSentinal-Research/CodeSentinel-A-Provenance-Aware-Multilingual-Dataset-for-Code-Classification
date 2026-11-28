#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; ++c) {
                    if (isValidSudoku(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    
    solveSudoku(board);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j > 0) cout << " ";
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
