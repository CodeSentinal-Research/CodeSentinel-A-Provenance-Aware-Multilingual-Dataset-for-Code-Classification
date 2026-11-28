#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, x;
    if (scanf("%d %d", &n, &x) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int l = 0, minLen = INT_MAX;
        long long curSum = 0;

        for (int r = 0; r < n; r++) {
            curSum += nums[r];
            while (curSum > x) {
                minLen = MIN(minLen, r - l + 1);
                curSum -= nums[l++];
            }
        }
        printf("%d\n", minLen != INT_MAX ? minLen : 0);
        free(nums);
    }
    return 0;
}