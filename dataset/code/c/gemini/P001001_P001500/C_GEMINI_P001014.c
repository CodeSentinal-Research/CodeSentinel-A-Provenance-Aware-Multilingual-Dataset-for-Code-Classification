#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int k, n;
    if (scanf("%d %d", &k, &n) == 2 && k > 0 && n > 0) {
        int total = k * n;
        int* arr = (int*)malloc(total * sizeof(int));
        for (int i = 0; i < total; i++) scanf("%d", &arr[i]);
        qsort(arr, total, sizeof(int), cmp);
        for (int i = 0; i < total; i++) {
            printf("%d%s", arr[i], (i == total - 1 ? "" : " "));
        }
        printf("\n");
        free(arr);
    }
    return 0;
}