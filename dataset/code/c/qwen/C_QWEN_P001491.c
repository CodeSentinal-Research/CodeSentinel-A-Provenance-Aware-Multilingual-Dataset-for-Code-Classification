#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    qsort(nums, n, sizeof(int), cmp);
    int min_diff = nums[k-1] - nums[0];
    for (int i = 1; i <= n - k; i++) {
        int diff = nums[i+k-1] - nums[i];
        if (diff < min_diff) min_diff = diff;
    }
    printf("%d\n", min_diff);
    return 0;
}
