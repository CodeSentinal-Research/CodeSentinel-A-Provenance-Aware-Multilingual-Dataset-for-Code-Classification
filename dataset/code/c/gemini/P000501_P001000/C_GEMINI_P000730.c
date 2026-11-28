#include <stdio.h>
#include <stdbool.h>
char board[32][32];
bool cols[32], d1[64], d2[64];
void backtrack(int n, int r) {
    if (r == n) {
        for (int i = 0; i < n; i++) printf("%s\n", board[i]);
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++) {
        if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
        cols[c] = d1[r + c] = d2[r - c + n] = true;
        board[r][c] = 'Q';
        backtrack(n, r + 1);
        board[r][c] = '.';
        cols[c] = d1[r + c] = d2[r - c + n] = false;
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) board[i][j] = '.';
            board[i][n] = '\0';
        }
        backtrack(n, 0);
    }
    return 0;
}