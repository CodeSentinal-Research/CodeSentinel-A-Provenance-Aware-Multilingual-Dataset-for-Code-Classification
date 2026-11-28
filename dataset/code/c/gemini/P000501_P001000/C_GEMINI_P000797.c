#include <stdio.h>
#define MAX_N 200005
int count[MAX_N * 2];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int offset = MAX_N;
        count[offset] = 1;
        int cur = 0; long long ans = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] == 1 ? 1 : -1);
            ans += count[cur + offset];
            count[cur + offset]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}