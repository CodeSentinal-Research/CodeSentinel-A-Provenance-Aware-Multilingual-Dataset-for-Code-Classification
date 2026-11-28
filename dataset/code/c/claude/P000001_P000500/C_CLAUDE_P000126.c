#include <stdlib.h>
#include <limits.h>
int cmpI(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int abs2(int x) { return x < 0 ? -x : x; }
int threeSumClosest(int* nums, int n, int target) {
    qsort(nums, n, sizeof(int), cmpI);
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (abs2(s - target) < abs2(closest - target)) closest = s;
            if (s < target) l++;
            else if (s > target) r--;
            else return s;
        }
    }
    return closest;
}
