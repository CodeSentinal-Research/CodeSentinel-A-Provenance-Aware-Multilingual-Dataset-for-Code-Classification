#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    long long diff = *(long long*)a - *(long long*)b;
    return diff < 0 ? -1 : (diff > 0 ? 1 : 0);
}
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int total = m + n;
        long long *arr = (long long *)malloc(total * sizeof(long long));
        for (int i = 0; i < total; i++) scanf("%lld", &arr[i]);
        qsort(arr, total, sizeof(long long), cmp);
        for (int i = 0; i < total; i++) {
            if (i > 0) printf(" ");
            printf("%lld", arr[i]);
        }
        printf("\n");
        free(arr);
    }
    return 0;
}