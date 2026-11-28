#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        long long maxSum = curSum;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            maxSum = MAX(maxSum, curSum);
        }
        printf("%lld\n", maxSum);
        free(nums);
    }
    return 0;
}