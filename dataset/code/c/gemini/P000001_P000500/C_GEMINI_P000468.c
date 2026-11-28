#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20005
int arr[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int m, n, k;
    if (scanf("%d %d %d", &m, &n, &k) == 3) {
        int tot = m + n;
        for (int i = 0; i < tot; i++) scanf("%d", &arr[i]);
        qsort(arr, tot, sizeof(int), cmp);
        printf("%d\n", arr[k - 1]);
    }
    return 0;
}