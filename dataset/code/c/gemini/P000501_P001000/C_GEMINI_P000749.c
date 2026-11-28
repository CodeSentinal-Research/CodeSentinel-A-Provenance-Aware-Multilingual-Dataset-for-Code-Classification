#include <stdio.h>
#include <string.h>
void var_jump_paths(int n, int m, int r, int c, char* path, int len) {
    if (r == n && c == m) {
        path[len] = '\0';
        printf("%s\n", path);
        return;
    }
    for (int k = 1; k <= m - c; k++) {
        char next_path[128];
        sprintf(next_path, "%sH%d", path, k);
        var_jump_paths(n, m, r, c + k, next_path, strlen(next_path));
    }
    for (int k = 1; k <= n - r; k++) {
        char next_path[128];
        sprintf(next_path, "%sV%d", path, k);
        var_jump_paths(n, m, r + k, c, next_path, strlen(next_path));
    }
    int limit = (n - r < m - c) ? n - r : m - c;
    for (int k = 1; k <= limit; k++) {
        char next_path[128];
        sprintf(next_path, "%sD%d", path, k);
        var_jump_paths(n, m, r + k, c + k, next_path, strlen(next_path));
    }
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        char path[128] = "";
        var_jump_paths(n, m, 1, 1, path, 0);
    }
    return 0;
}