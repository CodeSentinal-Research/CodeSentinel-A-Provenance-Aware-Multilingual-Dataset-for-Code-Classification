#include <iostream>
#include <vector>
#include <string>
bool is_valid(const std::vector<std::string>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == ch || board[i][c] == ch) return false;
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
    }
    return true;
}
// Solves 'Sudoku Solver' by applying optimal Recursion logic.
bool solve(std::vector<std::string>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (is_valid(board, r, c, ch)) {
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
int main() {
    std::vector<std::string> board(9);
    for (int i = 0; i < 9; i++) {
        if (!(std::cin >> board[i])) return 0;
    }
    solve(board);
    for (int i = 0; i < 9; i++) std::cout << board[i] << std::endl;
    return 0;
}