#include <stdio.h>
#include <string.h>

int n;
char stickers[50][20], target[20];
int min_s = 1000000;

void solve(char *t, int cnt) {
    if (!*t) {
        if (cnt < min_s) min_s = cnt;
        return;
    }
    if (cnt >= min_s - 1) return;
    for (int i = 0; i < n; i++) {
        char nt[20];
        strcpy(nt, t);
        for (int j = 0; stickers[i][j]; j++) {
            for (int k = 0; nt[k]; k++) {
                if (nt[k] == stickers[i][j]) {
                    nt[k] = '*';
                    break;
                }
            }
        }
        char nt2[20];
        int idx = 0;
        for (int k = 0; nt[k]; k++) {
            if (nt[k] != '*') nt2[idx++] = nt[k];
        }
        nt2[idx] = 0;
        solve(nt2, cnt + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", stickers[i]);
    scanf("%s", target);
    solve(target, 0);
    printf("%d\n", min_s == 1000000 ? -1 : min_s);
    return 0;
}
