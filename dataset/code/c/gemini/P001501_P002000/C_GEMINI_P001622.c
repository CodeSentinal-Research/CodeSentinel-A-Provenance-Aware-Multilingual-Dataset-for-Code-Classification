#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cur += x;
            if (cur > 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}