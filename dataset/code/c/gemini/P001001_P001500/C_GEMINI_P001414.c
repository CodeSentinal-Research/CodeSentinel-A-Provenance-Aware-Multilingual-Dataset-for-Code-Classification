#include <stdio.h>
#include <stdlib.h>

int cmpIntAbs(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            arr[i] = abs(arr[i]);
        }
        qsort(arr, n, sizeof(int), cmpIntAbs);

        int count = n > 0 ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) count++;
        }
        printf("%d\n", count);
        free(arr);
    }
    return 0;
}