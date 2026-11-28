#include <stdlib.h>

int cmpIntProd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int tupleSameProduct(int* nums, int numsSize) {
    int total = numsSize * (numsSize - 1) / 2;
    int* prods = (int*)malloc(total * sizeof(int));
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            prods[idx++] = nums[i] * nums[j];
        }
    }
    qsort(prods, total, sizeof(int), cmpIntProd);

    int ans = 0;
    int count = 1;

    for (int i = 1; i < total; i++) {
        if (prods[i] == prods[i - 1]) {
            count++;
        } else {
            ans += 8 * count * (count - 1) / 2;
            count = 1;
        }
    }
    ans += 8 * count * (count - 1) / 2;

    free(prods);
    return ans;
}