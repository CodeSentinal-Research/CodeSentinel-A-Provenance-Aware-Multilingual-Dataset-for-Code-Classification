#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i < k) maxVal = MAX(maxVal, x);
        }
        printf("%d\n", maxVal);
    }
    return 0;
}