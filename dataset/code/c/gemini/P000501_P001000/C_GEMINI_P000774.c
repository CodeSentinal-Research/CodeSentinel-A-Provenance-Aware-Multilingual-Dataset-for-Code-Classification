#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char board[32][32];
char word[64];
int n, m;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool backtrack(int r, int c, int idx) {
    if (word[idx] == '\0') return true;
    if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != word[idx]) return false;
    char temp = board[r][c];
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        if (backtrack(r + dr[i], c + dc[i], idx + 1)) return true;
    }
    board[r][c] = temp;
    return false;
}
int main() {
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char s[4]; scanf("%3s", s); board[i][j] = s[0];
            }
        }
        scanf("%63s", word);
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (backtrack(i, j, 0)) { found = true; break; }
            }
            if (found) break;
        }
        printf("%s\n", found ? "true" : "false");
    }
    return 0;
}