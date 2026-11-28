#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int min_idx = 0;
        int min_val;
        scanf("%d", &min_val);
        for (int i = 1; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (val < min_val) {
                min_val = val;
                min_idx = i;
            }
        }
        printf("%d\n", min_idx);
    }
    return 0;
}