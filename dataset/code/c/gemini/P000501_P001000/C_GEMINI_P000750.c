#include <stdio.h>
void dfs(int cur, int n) {
    if (cur > n) return;
    printf("%d\n", cur);
    for (int i = 0; i < 10; i++) {
        if (cur * 10 + i <= n) dfs(cur * 10 + i, n);
        else break;
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 1; i <= 9 && i <= n; i++) dfs(i, n);
    }
    return 0;
}