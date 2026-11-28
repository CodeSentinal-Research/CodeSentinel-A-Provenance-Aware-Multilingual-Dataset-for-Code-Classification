#include <stdio.h>

int r, c, g[15][15];
int max_g = 0;

void dfs(int i, int j, int sum) {
    if (sum > max_g) max_g = sum;
    int v = g[i][j];
    g[i][j] = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int d = 0; d < 4; d++) {
        int nx = i + dx[d], ny = j + dy[d];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny]) {
            dfs(nx, ny, sum + g[nx][ny]);
        }
    }
    g[i][j] = v;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j]) dfs(i, j, g[i][j]);
        }
    }
    printf("%d\n", max_g);
    return 0;
}
