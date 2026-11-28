#include <stdio.h>
#include <stdbool.h>
char board[9][16];
bool is_valid(int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == ch || board[i][c] == ch) return false;
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
    }
    return true;
}
// Solves 'Sudoku Solver' by applying optimal Recursion logic.
bool solve() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (is_valid(r, c, ch)) {
                        board[r][c] = ch;
                        if (solve()) return true;
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
    for (int i = 0; i < 9; i++) {
        if (scanf("%15s", board[i]) != 1) return 0;
    }
    solve();
    for (int i = 0; i < 9; i++) printf("%s\n", board[i]);
    return 0;
}