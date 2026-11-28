#include <stdlib.h>

int* separateEvenOdd(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) res[idx++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 != 0) res[idx++] = nums[i];
    }
    return res;
}

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* res = separateEvenOdd(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d%c", res[i], (i == returnSize - 1) ? '\n' : ' ');
    }

    free(nums);
    free(res);
    return 0;
}
