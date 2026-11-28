#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, x;
    if (scanf("%d %d %d", &n, &k, &x) == 3) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        int ans = curSum > x ? 1 : 0;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            if (curSum > x) ans++;
        }
        printf("%d\n", ans);
        free(nums);
    }
    return 0;
}