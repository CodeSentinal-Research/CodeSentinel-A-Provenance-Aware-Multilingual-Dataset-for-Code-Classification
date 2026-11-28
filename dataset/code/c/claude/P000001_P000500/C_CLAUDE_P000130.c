#include <stdlib.h>
int* nextSmallerElement(int* nums, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) res[i] = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && nums[stack[top]] > nums[i])
            res[stack[top--]] = nums[i];
        stack[++top] = i;
    }
    free(stack);
    return res;
}
