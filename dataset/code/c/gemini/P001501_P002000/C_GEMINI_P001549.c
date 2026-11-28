#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int nonPos = 0;
        for (int i = 0; i < k; i++) if (nums[i] <= 0) nonPos++;
        int ans = nonPos == 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (nums[i] <= 0) nonPos++;
            if (nums[i - k] <= 0) nonPos--;
            if (nonPos == 0) ans++;
        }
        printf("%d\n", ans);
        free(nums);
    }
    return 0;
}