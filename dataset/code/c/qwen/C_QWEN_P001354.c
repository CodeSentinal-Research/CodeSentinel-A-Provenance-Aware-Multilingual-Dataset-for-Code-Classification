#include <stdio.h>

int n;
int res[40], used[40];

int solve(int i) {
    if (i == 2 * n - 1) return 1;
    for (int v = n; v >= 1; v--) {
        if (v == 1) {
            if (!used[v]) {
                res[i] = v;
                used[v] = 1;
                if (solve(i + 1)) return 1;
                used[v] = 0;
            }
        } else {
            if (i + v < 2 * n - 1 && !used[v] && !res[i + v]) {
                res[i] = v;
                res[i + v] = v;
                used[v] = 1;
                if (solve(i + 1)) return 1;
                used[v] = 0;
                res[i + v] = 0;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++) res[i] = 0;
    if (solve(0)) {
        for (int i = 0; i < 2 * n - 1; i++) printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}
