#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        int closest = 0, min_diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            int diff = abs(v - target);
            if (diff < min_diff) {
                min_diff = diff;
                closest = v;
            }
        }
        printf("%d\n", closest);
    }
    return 0;
}