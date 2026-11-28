#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int b; scanf("%d", &b);
            ans = (ans << 1) | b;
        }
        printf("%d\n", ans);
    }
    return 0;
}