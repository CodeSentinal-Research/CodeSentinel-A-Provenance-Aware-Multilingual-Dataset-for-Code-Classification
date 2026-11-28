#include <stdbool.h>
bool isSortedAsc(int* nums, int n) {
    for (int i = 0; i < n - 1; i++)
        if (nums[i] > nums[i+1]) return false;
    return true;
}
