#include <stdio.h>
#include <string.h>

char p[10];
int n;
int res[10], used[10];

int solve(int i, int last) {
    if (i == n + 1) return 1;
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            if (p[i - 1] == 'I' && v < last) continue;
            if (p[i - 1] == 'D' && v > last) continue;
            res[i] = v;
            used[v] = 1;
            if (solve(i + 1, v)) return 1;
            used[v] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%s", p);
    n = strlen(p);
    solve(1, 0);
    for (int i = 1; i <= n; i++) printf("%d", res[i]);
    printf("\n");
    return 0;
}
