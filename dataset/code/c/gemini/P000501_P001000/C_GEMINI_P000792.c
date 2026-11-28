#include <stdio.h>
#define MAX_N 100005
int count[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int goal; scanf("%d", &goal);
        count[0] = 1;
        int cur = 0; long long ans = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (cur >= goal) ans += count[cur - goal];
            count[cur]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}