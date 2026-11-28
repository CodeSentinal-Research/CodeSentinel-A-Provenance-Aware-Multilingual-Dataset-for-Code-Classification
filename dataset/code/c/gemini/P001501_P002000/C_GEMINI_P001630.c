#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        long long ops = 0;
        for (int i = 1; i < n; i++) {
            ops += abs(nums[i] - nums[i - 1]);
        }
        printf("%lld\n", ops);
        free(nums);
    }
    return 0;
}