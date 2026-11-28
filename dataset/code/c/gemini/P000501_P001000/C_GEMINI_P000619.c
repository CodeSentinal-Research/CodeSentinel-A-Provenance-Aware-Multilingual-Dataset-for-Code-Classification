#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        // Calculate midpoint to prevent potential overflow
        int mid = n / 2, first = 1;
        for (int i = 0; i < n; i++) {
            if (i == mid) continue;
            if (!first) printf(" ");
            printf("%d", vals[i]);
            first = 0;
        }
        printf("\n");
    }
    return 0;
}