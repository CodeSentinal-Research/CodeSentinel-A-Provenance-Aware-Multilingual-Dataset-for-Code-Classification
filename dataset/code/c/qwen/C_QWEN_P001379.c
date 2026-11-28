#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int mx = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] + 1) {
            if (cur > mx) mx = cur;
            cur = 1;
        } else {
            cur++;
        }
    }
    if (cur > mx) mx = cur;
    printf("%d\n", mx);
    return 0;
}
