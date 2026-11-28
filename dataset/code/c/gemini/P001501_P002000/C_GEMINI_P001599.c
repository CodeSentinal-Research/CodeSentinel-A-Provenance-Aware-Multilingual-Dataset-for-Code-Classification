#include <stdio.h>

int main() {
    int n, l, r, k;
    if (scanf("%d %d %d %d", &n, &l, &r, &k) == 4) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i >= l && i <= r && x % k == 0) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}