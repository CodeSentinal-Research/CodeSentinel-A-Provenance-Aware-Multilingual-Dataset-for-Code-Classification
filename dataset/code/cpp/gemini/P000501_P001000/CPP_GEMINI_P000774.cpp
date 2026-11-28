#include <iostream>
#include <vector>
#include <string>
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool backtrack(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int idx) {
    if (idx == (int)word.length()) return true;
    if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size() || board[r][c] != word[idx]) return false;
    char temp = board[r][c];
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        if (backtrack(board, word, r + dr[i], c + dc[i], idx + 1)) return true;
    }
    board[r][c] = temp;
    return false;
}
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<char>> board(n, std::vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) std::cin >> board[i][j];
        }
        std::string word; std::cin >> word;
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(board, word, i, j, 0)) { found = true; break; }
            }
            if (found) break;
        }
        std::cout << (found ? "true" : "false") << std::endl;
    }
    return 0;
}