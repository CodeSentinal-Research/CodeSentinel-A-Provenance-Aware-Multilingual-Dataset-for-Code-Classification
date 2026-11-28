#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            ans ^= v;
        }
        printf("%d\n", ans);
    }
    return 0;
}