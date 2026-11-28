#include <stdio.h>
#define MAX_N 100005
long long nums[MAX_N], prefix[MAX_N];
int q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%lld", &nums[i]);
        long long k;
        scanf("%lld", &k);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        int head = 0, tail = 0;
        int min_len = n + 1;
        for (int i = 0; i <= n; i++) {
            while (head < tail && prefix[i] - prefix[q[head]] >= k) {
                int len = i - q[head++];
                if (len < min_len) min_len = len;
            }
            while (head < tail && prefix[q[tail - 1]] >= prefix[i]) {
                tail--;
            }
            q[tail++] = i;
        }
        printf("%d\n", min_len <= n ? min_len : -1);
    }
    return 0;
}