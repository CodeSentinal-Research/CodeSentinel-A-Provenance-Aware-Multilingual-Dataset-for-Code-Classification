#include <vector>

class Solution {
    bool isValid(const std::vector<std::vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch || board[i][c] == ch) return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    // Solves 'Sudoku Solver' by applying optimal Backtracking logic.
    bool solve(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;
                            if (solve(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    // Solves 'Sudoku Solver' by applying optimal Backtracking logic.
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
};