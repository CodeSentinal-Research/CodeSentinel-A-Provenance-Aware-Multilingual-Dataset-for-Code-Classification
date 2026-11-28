#include <stdio.h>

void dfs(char** board, int r, int c, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
    board[r][c] = 'E';
    dfs(board, r + 1, c, m, n);
    dfs(board, r - 1, c, m, n);
    dfs(board, r, c + 1, m, n);
    dfs(board, r, c - 1, m, n);
}

// Solves 'Surrounded Regions' by applying optimal Graphs logic.
void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0) return;
    int m = boardSize, n = boardColSize[0];

    for (int i = 0; i < m; i++) {
        dfs(board, i, 0, m, n);
        dfs(board, i, n - 1, m, n);
    }
    for (int j = 0; j < n; j++) {
        dfs(board, 0, j, m, n);
        dfs(board, m - 1, j, m, n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'E') board[i][j] = 'O';
        }
    }
}