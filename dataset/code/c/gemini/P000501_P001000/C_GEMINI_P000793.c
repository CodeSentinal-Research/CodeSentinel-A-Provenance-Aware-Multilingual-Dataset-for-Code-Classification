#include <stdio.h>
#define MAX_N 100005
int count[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        count[0] = 1;
        int cur = 0; long long ans = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] % 2 != 0 ? 1 : 0);
            if (cur >= k) ans += count[cur - k];
            count[cur]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}