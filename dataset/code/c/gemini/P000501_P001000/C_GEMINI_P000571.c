#include <stdio.h>
int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}