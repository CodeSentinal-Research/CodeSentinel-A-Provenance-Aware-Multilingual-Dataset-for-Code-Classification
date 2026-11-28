#include <stdlib.h>
#include <stdbool.h>

int cmpDup(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpDup);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("No\n");
        return 0;
    }

    int *nums = (int*)malloc(n * sizeof(int));
    if (!nums) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (containsDuplicate(nums, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(nums);
    return 0;
}
