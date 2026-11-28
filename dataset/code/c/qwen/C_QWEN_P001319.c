#include <stdio.h>
#include <string.h>

int r, c, nw;
char g[20][21], words[100][21];

int dfs(int i, int j, int w, int k) {
    if (!words[w][k]) return 1;
    if (i < 0 || i >= r || j < 0 || j >= c || g[i][j] != words[w][k]) return 0;
    char t = g[i][j];
    g[i][j] = '#';
    int res = dfs(i + 1, j, w, k + 1) || dfs(i - 1, j, w, k + 1) ||
              dfs(i, j + 1, w, k + 1) || dfs(i, j - 1, w, k + 1);
    g[i][j] = t;
    return res;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", g[i]);
    scanf("%d", &nw);
    for (int i = 0; i < nw; i++) scanf("%s", words[i]);
    for (int w = 0; w < nw; w++) {
        int f = 0;
        for (int i = 0; i < r && !f; i++) {
            for (int j = 0; j < c && !f; j++) {
                if (dfs(i, j, w, 0)) f = 1;
            }
        }
        if (f) printf("%s\n", words[w]);
    }
    return 0;
}
