#include <stdio.h>
#include <string.h>

int r, c;
char g[20][21], w[101];

int dfs(int i, int j, int k) {
    if (!w[k]) return 1;
    if (i < 0 || i >= r || j < 0 || j >= c || g[i][j] != w[k]) return 0;
    char t = g[i][j];
    g[i][j] = '#';
    int res = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) ||
              dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
    g[i][j] = t;
    return res;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", g[i]);
    scanf("%s", w);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dfs(i, j, 0)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
