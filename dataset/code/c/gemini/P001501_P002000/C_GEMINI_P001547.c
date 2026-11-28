#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int curOdds = 0;
        for (int i = 0; i < k; i++) if (nums[i] % 2 != 0) curOdds++;
        int maxOdds = curOdds;

        for (int i = k; i < n; i++) {
            if (nums[i] % 2 != 0) curOdds++;
            if (nums[i - k] % 2 != 0) curOdds--;
            maxOdds = MAX(maxOdds, curOdds);
        }
        printf("%d\n", maxOdds);
        free(nums);
    }
    return 0;
}