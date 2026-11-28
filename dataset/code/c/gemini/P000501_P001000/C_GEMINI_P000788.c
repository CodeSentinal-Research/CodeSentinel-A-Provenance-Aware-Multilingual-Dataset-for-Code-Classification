#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        long long cur = 0;
        for (int i = 0; i < k; i++) cur += nums[i];
        long long max_sum = cur;
        for (int i = k; i < n; i++) {
            cur += nums[i] - nums[i - k];
            if (cur > max_sum) max_sum = cur;
        }
        printf("%.5f\n", (double)max_sum / k);
    }
    return 0;
}