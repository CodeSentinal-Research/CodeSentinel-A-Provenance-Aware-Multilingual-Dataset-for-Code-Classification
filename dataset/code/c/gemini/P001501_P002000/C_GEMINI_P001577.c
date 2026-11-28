#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int nonInc = 0;
        for (int i = 0; i < k - 1; i++) if (nums[i] >= nums[i + 1]) nonInc++;
        int ans = nonInc == 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (nums[i - 1] >= nums[i]) nonInc++;
            if (nums[i - k] >= nums[i - k + 1]) nonInc--;
            if (nonInc == 0) ans++;
        }
        printf("%d\n", ans);
        free(nums);
    }
    return 0;
}