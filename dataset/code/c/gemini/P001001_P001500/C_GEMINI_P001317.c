#include <stdio.h>
#include <stdbool.h>

int moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Solves 'Knight's Tour' by applying optimal Backtracking logic.
bool solve(int r, int c, int step, int n, int board[][20]) {
    if (step == n * n) return true;
    for (int i = 0; i < 8; i++) {
        int nr = r + moves[i][0], nc = c + moves[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            board[nr][nc] = step;
            if (solve(nr, nc, step + 1, n, board)) return true;
            board[nr][nc] = -1;
        }
    }
    return false;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int board[20][20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) board[i][j] = -1;
        }
        board[0][0] = 0;
        solve(0, 0, 1, n, board);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d%s", board[i][j], j + 1 == n ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}