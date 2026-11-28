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
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] - nums[i] == k) {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
