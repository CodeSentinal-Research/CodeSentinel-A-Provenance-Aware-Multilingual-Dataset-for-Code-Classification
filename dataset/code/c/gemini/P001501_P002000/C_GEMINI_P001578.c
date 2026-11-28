#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* count = (int*)calloc(100005, sizeof(int));
        int distinct = 0;

        for (int i = 0; i < k; i++) {
            if (count[nums[i]]++ == 0) distinct++;
        }
        int ans = distinct == k ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (count[nums[i]]++ == 0) distinct++;
            if (--count[nums[i - k]] == 0) distinct--;
            if (distinct == k) ans++;
        }
        printf("%d\n", ans);
        free(nums);
        free(count);
    }
    return 0;
}