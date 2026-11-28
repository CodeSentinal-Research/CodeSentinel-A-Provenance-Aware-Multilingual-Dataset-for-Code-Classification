#include <stdio.h>

int n, m;
int a[10][10], used[100];

int solve(int i, int j) {
    if (i == n) return 1;
    if (j == n) return solve(i + 1, 0);
    if (a[i][j]) return solve(i, j + 1);
    for (int v = 1; v <= n * n; v++) {
        if (!used[v]) {
            a[i][j] = v;
            used[v] = 1;
            if (solve(i, j + 1)) return 1;
            a[i][j] = 0;
            used[v] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (solve(0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
