#include <iostream>
#include <vector>
#include <string>
void backtrack(int n, int r, std::vector<std::string>& board, std::vector<bool>& cols, std::vector<bool>& d1, std::vector<bool>& d2) {
    if (r == n) {
        for (int i = 0; i < n; i++) std::cout << board[i] << std::endl;
        std::cout << std::endl;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
        cols[c] = d1[r + c] = d2[r - c + n] = true;
        board[r][c] = 'Q';
        backtrack(n, r + 1, board, cols, d1, d2);
        board[r][c] = '.';
        cols[c] = d1[r + c] = d2[r - c + n] = false;
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<bool> cols(n, false), d1(2 * n, false), d2(2 * n, false);
        backtrack(n, 0, board, cols, d1, d2);
    }
    return 0;
}