#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int l = 0, r = n - k;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (x - nums[mid] > nums[mid+k] - x) l = mid + 1;
        else r = mid;
    }
    for (int i = l; i < l + k; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
