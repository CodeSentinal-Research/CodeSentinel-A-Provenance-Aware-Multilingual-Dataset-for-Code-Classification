#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int l = 0, r = n - 1, first = 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            if (!first) printf(" ");
            printf("%d", vals[l]);
            first = 0;
            if (l != r) printf(" %d", vals[r]);
            l++; r--;
        }
        printf("\n");
    }
    return 0;
}