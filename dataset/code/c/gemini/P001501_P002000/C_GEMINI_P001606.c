#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* count = (int*)calloc(2 * n + 1, sizeof(int));
        count[n] = 1;
        int curSum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            curSum += (nums[i] == 1 ? 1 : -1);
            ans += count[curSum + n];
            count[curSum + n]++;
        }
        printf("%lld\n", ans);
        free(nums);
        free(count);
    }
    return 0;
}