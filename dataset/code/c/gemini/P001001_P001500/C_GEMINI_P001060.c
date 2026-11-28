#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}