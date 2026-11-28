#include <stdio.h>
#define MAX_N 10005
long long h[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
        long long max_sum = 0;
        for (int peak = 0; peak < n; peak++) {
            long long curr_sum = h[peak], cur = h[peak];
            for (int i = peak - 1; i >= 0; i--) {
                if (h[i] < cur) cur = h[i];
                curr_sum += cur;
            }
            cur = h[peak];
            for (int i = peak + 1; i < n; i++) {
                if (h[i] < cur) cur = h[i];
                curr_sum += cur;
            }
            if (curr_sum > max_sum) max_sum = curr_sum;
        }
        printf("%lld\n", max_sum);
    }
    return 0;
}