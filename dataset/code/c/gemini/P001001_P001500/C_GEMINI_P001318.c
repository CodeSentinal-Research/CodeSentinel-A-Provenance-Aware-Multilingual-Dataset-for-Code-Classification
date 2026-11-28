#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int m, int n, char* word, int r, int c, int k) {
    if (word[k] == '\0') return true;
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[k]) return false;

    char tmp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(board, m, n, word, r + 1, c, k + 1) ||
                 dfs(board, m, n, word, r - 1, c, k + 1) ||
                 dfs(board, m, n, word, r, c + 1, k + 1) ||
                 dfs(board, m, n, word, r, c - 1, k + 1);

    board[r][c] = tmp;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, m, n, word, i, j, 0)) return true;
        }
    }
    return false;
}