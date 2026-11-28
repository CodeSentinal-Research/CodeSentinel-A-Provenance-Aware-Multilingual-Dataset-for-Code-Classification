#include <stdio.h>

int main() {
    int n, x;
    if (scanf("%d %d", &n, &x) == 2) {
        long long curSum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            curSum += val;
            if (curSum >= x && ans == -1) {
                ans = i + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}