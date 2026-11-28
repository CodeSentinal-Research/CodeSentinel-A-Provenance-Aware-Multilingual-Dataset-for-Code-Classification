#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        double curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        printf("%.2f", curSum / k);

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            printf(" %.2f", curSum / k);
        }
        printf("\n");
        free(nums);
    }
    return 0;
}