#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, l, r;
    if (scanf("%d %d %d", &n, &l, &r) == 3) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        long long sum = 0;
        for (int i = l; i <= r; i += 2) sum += nums[i];
        printf("%lld\n", sum);
        free(nums);
    }
    return 0;
}