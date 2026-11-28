#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int l = 0, odds = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 != 0) odds++;
            while (odds > k) {
                if (nums[l++] % 2 != 0) odds--;
            }
            maxLen = MAX(maxLen, r - l + 1);
        }
        printf("%d\n", maxLen);
        free(nums);
    }
    return 0;
}