#include <stdio.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        long long cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cur += x;
            if (cur % k == 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}