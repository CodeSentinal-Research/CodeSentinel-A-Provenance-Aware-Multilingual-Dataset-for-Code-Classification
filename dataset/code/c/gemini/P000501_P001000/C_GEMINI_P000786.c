#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int nums[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long total = 0;
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); total += nums[i]; }
        long long left = 0;
        for (int i = 0; i < n; i++) {
            long long right = total - left - nums[i];
            printf("%lld%s", llabs(left - right), i == n - 1 ? "" : " ");
            left += nums[i];
        }
        printf("\n");
    }
    return 0;
}