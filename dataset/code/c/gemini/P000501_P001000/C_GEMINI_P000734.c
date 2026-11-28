#include <stdio.h>
#include <stdbool.h>
int board[32][32];
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool backtrack(int n, int r, int c, int step) {
    if (step == n * n) return true;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            board[nr][nc] = step;
            if (backtrack(n, nr, nc, step + 1)) return true;
            board[nr][nc] = -1;
        }
    }
    return false;
}
int main() {
    int n, sr, sc;
    if (scanf("%d %d %d", &n, &sr, &sc) == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) board[i][j] = -1;
        }
        board[sr][sc] = 0;
        if (backtrack(n, sr, sc, 1)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%d%s", board[i][j], j == n - 1 ? "" : " ");
                printf("\n");
            }
        } else {
            printf("-1\n");
        }
    }
    return 0;
}