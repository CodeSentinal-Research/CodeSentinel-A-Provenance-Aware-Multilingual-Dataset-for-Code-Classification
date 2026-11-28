#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int c1 = 0, c2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (cnt1 > 0 && x == c1) cnt1++;
        else if (cnt2 > 0 && x == c2) cnt2++;
        else if (cnt1 == 0) { c1 = x; cnt1 = 1; }
        else if (cnt2 == 0) { c2 = x; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }

    cnt1 = 0; cnt2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == c1) cnt1++;
        else if (nums[i] == c2) cnt2++;
    }

    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;
    if (cnt1 > numsSize / 3) res[(*returnSize)++] = c1;
    if (c2 != c1 && cnt2 > numsSize / 3) res[(*returnSize)++] = c2;
    return res;
}