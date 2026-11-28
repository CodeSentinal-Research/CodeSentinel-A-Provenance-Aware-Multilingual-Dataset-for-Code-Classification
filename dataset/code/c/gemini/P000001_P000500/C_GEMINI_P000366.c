#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int max_idx = 0;
        int max_val;
        scanf("%d", &max_val);
        for (int i = 1; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val > max_val) {
                max_val = val;
                max_idx = i;
            }
        }
        printf("%d\n", max_idx);
    }
    return 0;
}