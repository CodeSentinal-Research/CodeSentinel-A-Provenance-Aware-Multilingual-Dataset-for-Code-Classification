#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cur ^= x;
            printf("%d%s", cur, i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}