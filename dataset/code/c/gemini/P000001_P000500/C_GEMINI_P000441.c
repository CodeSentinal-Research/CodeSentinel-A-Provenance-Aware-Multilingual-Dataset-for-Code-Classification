#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int max_val;
        scanf("%d", &max_val);
        for (int i = 1; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v > max_val) max_val = v;
        }
        printf("%d\n", max_val);
    }
    return 0;
}