#include <stdio.h>

int r, c, g[20][20];
int empty = 0, ans = 0;

void dfs(int i, int j, int rem) {
    if (i < 0 || i >= r || j < 0 || j >= c || g[i][j] == -1) return;
    if (g[i][j] == 2) {
        if (!rem) ans++;
        return;
    }
    g[i][j] = -1;
    dfs(i + 1, j, rem - 1);
    dfs(i - 1, j, rem - 1);
    dfs(i, j + 1, rem - 1);
    dfs(i, j - 1, rem - 1);
    g[i][j] = 0;
}

int main() {
    scanf("%d%d", &r, &c);
    int si, sj;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 1) {
                si = i;
                sj = j;
            } else if (g[i][j] == 0) {
                empty++;
            }
        }
    }
    dfs(si, sj, empty + 1);
    printf("%d\n", ans);
    return 0;
}
