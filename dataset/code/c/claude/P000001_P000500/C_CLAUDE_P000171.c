#include <string.h>
int* segregate01(int* nums, int n) {
    int zeros = 0;
    for (int i = 0; i < n; i++) if (nums[i] == 0) zeros++;
    memset(nums, 0, zeros * sizeof(int));
    for (int i = zeros; i < n; i++) nums[i] = 1;
    return nums;
}
