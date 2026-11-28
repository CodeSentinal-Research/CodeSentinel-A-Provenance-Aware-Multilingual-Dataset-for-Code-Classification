#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int max_v = -2000000000;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v > max_v) max_v = v;
        }
        printf("%d\n", max_v);
    }
    return 0;
}