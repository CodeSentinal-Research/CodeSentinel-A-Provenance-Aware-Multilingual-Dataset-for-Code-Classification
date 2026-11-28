#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            cur += x;
            printf("%lld%s", cur, i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}