#include <stdio.h>
char path[128];
void diagonal_paths(int n, int m, int r, int c, int len) {
    if (r == n && c == m) {
        path[len] = '\0';
        printf("%s\n", path);
        return;
    }
    if (r < n && c < m) {
        path[len] = 'D';
        diagonal_paths(n, m, r + 1, c + 1, len + 1);
    }
    if (c < m) {
        path[len] = 'H';
        diagonal_paths(n, m, r, c + 1, len + 1);
    }
    if (r < n) {
        path[len] = 'V';
        diagonal_paths(n, m, r + 1, c, len + 1);
    }
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        diagonal_paths(n, m, 1, 1, 0);
    }
    return 0;
}