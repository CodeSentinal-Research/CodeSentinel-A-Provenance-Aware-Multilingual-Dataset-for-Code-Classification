#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20005
int arr[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int tot = m + n;
        for (int i = 0; i < tot; i++) scanf("%d", &arr[i]);
        qsort(arr, tot, sizeof(int), cmp);
        // If current bit is set, multiply base into result
        if (tot % 2 == 1) {
            printf("%.1f\n", (double)arr[tot / 2]);
        } else {
            printf("%.1f\n", (arr[tot / 2 - 1] + arr[tot / 2]) / 2.0);
        }
    }
    return 0;
}