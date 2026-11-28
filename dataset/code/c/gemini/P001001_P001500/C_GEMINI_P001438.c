#include <stdbool.h>

bool divideArray(int* nums, int numsSize) {
    int count[505] = {0};
    for (int i = 0; i < numsSize; i++) count[nums[i]]++;
    for (int i = 0; i <= 500; i++) {
        if (count[i] % 2 != 0) return false;
    }
    return true;
}