#include <stdlib.h>
#include <limits.h>

int* leaders(int* arr, int arrSize, int* returnSize) {
    int* temp = (int*)malloc(arrSize * sizeof(int));
    int count = 0;
    int maxFromRight = INT_MIN;

    for (int i = arrSize - 1; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            temp[count++] = arr[i];
            maxFromRight = arr[i];
        }
    }

    *returnSize = count;
    int* res = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        res[i] = temp[count - 1 - i];
    }
    free(temp);
    return res;
}