#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int maxDiff = 0;
        for (int i = 0; i <= n - k; i++) {
            maxDiff = MAX(maxDiff, abs(nums[i + k - 1] - nums[i]));
        }
        printf("%d\n", maxDiff);
        free(nums);
    }
    return 0;
}