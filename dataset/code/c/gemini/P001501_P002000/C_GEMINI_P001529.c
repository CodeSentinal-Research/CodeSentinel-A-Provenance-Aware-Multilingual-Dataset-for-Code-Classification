#include <stdio.h>
#include <stdlib.h>

long long atMostK(int* nums, int n, int k) {
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
    free(count);
    return ans;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%lld\n", atMostK(nums, n, k) - atMostK(nums, n, k - 1));
        free(nums);
    }
    return 0;
}