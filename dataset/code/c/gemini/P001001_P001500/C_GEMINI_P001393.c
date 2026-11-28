#include <stdbool.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        int sum = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            sum += nums[j];
            if (sum % k == 0) return true;
        }
    }
    return false;
}