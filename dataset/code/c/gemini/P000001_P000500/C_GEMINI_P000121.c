int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) candidate = nums[i];
        count += (nums[i] == candidate ? 1 : -1);
    }
    return candidate;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (!nums) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = majorityElement(nums, n);
    printf("%d\n", result);

    free(nums);
    return 0;
}
