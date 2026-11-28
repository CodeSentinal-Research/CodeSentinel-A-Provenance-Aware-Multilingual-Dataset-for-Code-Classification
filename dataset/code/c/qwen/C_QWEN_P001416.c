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
    
    qsort(nums, n, sizeof(int), cmp);
    int max_len = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] == 1) {
            int len = 2;
            while (i + len < n && nums[i + len] - nums[i + len - 1] <= 1) {
                if (nums[i + len] - nums[i + len - 1] == 1) len++;
                else break;
            }
            if (len > max_len) max_len = len;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
