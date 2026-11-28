#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v == i && ans == -1) ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}