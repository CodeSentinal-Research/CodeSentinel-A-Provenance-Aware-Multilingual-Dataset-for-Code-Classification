#include <stdlib.h>

int* twoOddNum(int* arr, int n, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    int xorAll = 0;
    for (int i = 0; i < n; i++) xorAll ^= arr[i];

    int diffBit = xorAll & (-xorAll);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & diffBit) x ^= arr[i];
        else y ^= arr[i];
    }

    res[0] = x > y ? x : y;
    res[1] = x > y ? y : x;
    return res;
}