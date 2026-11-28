#include <stdio.h>

int n;
int m[20][20], vis[20][20];
char path[400];

void dfs(int r, int c, int len) {
    if (r == n - 1 && c == n - 1) {
        path[len] = '\0';
        printf("%s\n", path);
        return;
    }
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, 1, -1, 0};
    char dc2[] = {'D', 'R', 'L', 'U'};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && m[nr][nc]) {
            vis[nr][nc] = 1;
            path[len] = dc2[i];
            dfs(nr, nc, len + 1);
            vis[nr][nc] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    vis[0][0] = 1;
    dfs(0, 0, 0);
    return 0;
}
