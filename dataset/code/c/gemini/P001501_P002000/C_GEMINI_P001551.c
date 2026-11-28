#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int l = 0, maxLen = 0;
        long long curSum = 0;

        for (int r = 0; r < n; r++) {
            curSum += nums[r];
            while (curSum > k && l <= r) {
                curSum -= nums[l++];
            }
            if (curSum <= k) {
                maxLen = MAX(maxLen, r - l + 1);
            }
        }
        printf("%d\n", maxLen);
        free(nums);
    }
    return 0;
}