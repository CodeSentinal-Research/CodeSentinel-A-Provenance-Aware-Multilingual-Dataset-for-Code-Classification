#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int subarrayBitwiseORs(int* arr, int arrSize) {
    int* all = (int*)malloc(arrSize * 32 * sizeof(int));
    int total = 0;
    int* cur = (int*)malloc(32 * sizeof(int));
    int curSize = 0;

    for (int i = 0; i < arrSize; i++) {
        int* next = (int*)malloc(33 * sizeof(int));
        next[0] = arr[i];
        int nextSize = 1;
        for (int j = 0; j < curSize; j++) {
            int val = arr[i] | cur[j];
            int exists = 0;
            for (int k = 0; k < nextSize; k++) {
                if (next[k] == val) { exists = 1; break; }
            }
            if (!exists) next[nextSize++] = val;
        }
        free(cur);
        cur = next;
        curSize = nextSize;
        for (int j = 0; j < curSize; j++) {
            all[total++] = cur[j];
        }
    }
    free(cur);
    qsort(all, total, sizeof(int), cmp);
    int unique = (total > 0) ? 1 : 0;
    for (int i = 1; i < total; i++) {
        if (all[i] != all[i - 1]) unique++;
    }
    free(all);
    return unique;
}