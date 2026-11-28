#include <stdio.h>
#include <string.h>

int r, c, n;
char g[20][21], words[100][21];

int solve() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == '-') {
                for (int w = 0; w < n; w++) {
                    int len = strlen(words[w]);
                    int ok = 1;
                    if (j + len <= c) {
                        for (int k = 0; k < len; k++) {
                            if (g[i][j + k] != '-' && g[i][j + k] != words[w][k]) {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok) {
                            for (int k = 0; k < len; k++) g[i][j + k] = words[w][k];
                            if (solve()) return 1;
                            for (int k = 0; k < len; k++) g[i][j + k] = '-';
                        }
                    }
                    ok = 1;
                    if (i + len <= r) {
                        for (int k = 0; k < len; k++) {
                            if (g[i + k][j] != '-' && g[i + k][j] != words[w][k]) {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok) {
                            for (int k = 0; k < len; k++) g[i + k][j] = words[w][k];
                            if (solve()) return 1;
                            for (int k = 0; k < len; k++) g[i + k][j] = '-';
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", g[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    solve();
    for (int i = 0; i < r; i++) printf("%s\n", g[i]);
    return 0;
}
