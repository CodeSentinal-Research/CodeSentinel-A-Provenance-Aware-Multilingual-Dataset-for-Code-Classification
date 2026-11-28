#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmpInt);
    int minDiff = 2000000000;
    for (int i = 1; i < arrSize; i++) {
        minDiff = MIN(minDiff, arr[i] - arr[i - 1]);
    }

    int** res = (int**)malloc(arrSize * sizeof(int*));
    int count = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == minDiff) {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = arr[i - 1];
            res[count][1] = arr[i];
            count++;
        }
    }

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) (*returnColumnSizes)[i] = 2;
    return res;
}