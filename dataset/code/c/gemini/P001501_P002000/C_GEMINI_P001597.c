#include <stdio.h>

int main() {
    int n, l, r, x;
    if (scanf("%d %d %d %d", &n, &l, &r, &x) == 4) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (i >= l && i <= r && val == x) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}