#include <limits.h>
int secondLargest(int* nums, int n) {
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] > first) { second = first; first = nums[i]; }
        else if (nums[i] > second && nums[i] != first) second = nums[i];
    }
    return second == INT_MIN ? -1 : second;
}
