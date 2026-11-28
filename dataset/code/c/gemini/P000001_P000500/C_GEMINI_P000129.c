#include <stdlib.h>

int* nextGreaterElement(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;

    for (int i = numsSize - 1; i >= 0; i--) {
        while (top >= 0 && stack[top] <= nums[i]) {
            top--;
        }
        res[i] = (top >= 0) ? stack[top] : -1;
        stack[++top] = nums[i];
    }
    free(stack);
    return res;
}