#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    qsort(nums, n, sizeof(int), cmp);
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < abs(closest - target)) closest = sum;
            if (sum < target) l++;
            else if (sum > target) r--;
            else return printf("%d\n", sum), 0;
        }
    }
    printf("%d\n", closest);
    return 0;
}
