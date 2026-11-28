#include <stdlib.h>

// Simple fallback for C test harness
int numberOfArithmeticSlices(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            long long diff = (long long)nums[i] - nums[j];
            for (int k = 0; k < j; k++) {
                if ((long long)nums[j] - nums[k] == diff) {
                    total++;
                }
            }
        }
    }
    return total;
}