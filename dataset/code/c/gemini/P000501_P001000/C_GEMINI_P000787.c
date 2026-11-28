#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long total = 0;
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); total += nums[i]; }
        long long left_sum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (left_sum == total - left_sum - nums[i]) {
                ans = i;
                break;
            }
            left_sum += nums[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}