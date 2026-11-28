#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int res[n];
    int l = 0, r = n - 1, idx = n - 1;
    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r])) res[idx--] = nums[l++] * nums[l];
        else res[idx--] = nums[r--] * nums[r];
    }
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
