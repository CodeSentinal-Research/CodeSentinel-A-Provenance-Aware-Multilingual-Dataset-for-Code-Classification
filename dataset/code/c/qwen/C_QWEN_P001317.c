#include <stdio.h>

int n;
int b[8][8];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int solve(int x, int y, int mv) {
    if (mv == n * n) return 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !b[nx][ny]) {
            b[nx][ny] = mv + 1;
            if (solve(nx, ny, mv + 1)) return 1;
            b[nx][ny] = 0;
        }
    }
    return 0;
}

int main() {
    int sx, sy;
    scanf("%d%d%d", &n, &sx, &sy);
    b[sx][sy] = 1;
    if (solve(sx, sy, 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
