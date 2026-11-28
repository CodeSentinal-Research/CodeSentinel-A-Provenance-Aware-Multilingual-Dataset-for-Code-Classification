int missingNumber(int* nums, int numsSize) {
    int sum = numsSize * (numsSize + 1) / 2;
    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", missingNumber(nums, n));

    free(nums);
    return 0;
}
