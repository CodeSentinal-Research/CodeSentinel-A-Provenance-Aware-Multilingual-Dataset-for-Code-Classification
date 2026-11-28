#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* count = (int*)calloc(100005, sizeof(int));
        int distinct = 0, l = 0;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            if (count[nums[r]]++ == 0) distinct++;
            while (distinct > k) {
                if (--count[nums[l]] == 0) distinct--;
                l++;
            }
            ans += r - l + 1;
        }
        printf("%lld\n", ans);
        free(nums);
        free(count);
    }
    return 0;
}