#include <limits.h>
int secondSmallest(int* nums, int n) {
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nums[i] < first) { second = first; first = nums[i]; }
        else if (nums[i] < second && nums[i] != first) second = nums[i];
    }
    return second == INT_MAX ? -1 : second;
}
