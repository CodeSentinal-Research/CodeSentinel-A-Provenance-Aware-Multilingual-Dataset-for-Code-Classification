#include <stdio.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i < k) minVal = MIN(minVal, x);
        }
        printf("%d\n", minVal);
    }
    return 0;
}