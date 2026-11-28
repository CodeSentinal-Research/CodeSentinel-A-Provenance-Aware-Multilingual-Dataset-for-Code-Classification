#include <stdlib.h>

// Sorts the input array into ordered sequence.
int cmpUnionUnsorted(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int doUnion(int* arr1, int n, int* arr2, int m) {
    int total = n + m;
    int* all = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < n; i++) all[i] = arr1[i];
    for (int i = 0; i < m; i++) all[n + i] = arr2[i];

    qsort(all, total, sizeof(int), cmpUnionUnsorted);

    int count = 0;
    for (int i = 0; i < total; i++) {
        if (i == 0 || all[i] != all[i - 1]) count++;
    }
    free(all);
    return count;
}