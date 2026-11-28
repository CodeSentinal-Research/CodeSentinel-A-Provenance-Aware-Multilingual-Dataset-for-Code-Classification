#include <stdio.h>
#define MAX_N 100005
long long h[MAX_N], left[MAX_N], right[MAX_N];
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && h[st[top]] >= h[i]) top--;
            left[i] = (top == -1) ? h[i] * (i + 1) : left[st[top]] + h[i] * (i - st[top]);
            st[++top] = i;
        }
        top = -1;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && h[st[top]] >= h[i]) top--;
            right[i] = (top == -1) ? h[i] * (n - i) : right[st[top]] + h[i] * (st[top] - i);
            st[++top] = i;
        }
        long long max_sum = 0;
        for (int i = 0; i < n; i++) {
            long long cur = left[i] + right[i] - h[i];
            if (cur > max_sum) max_sum = cur;
        }
        printf("%lld\n", max_sum);
    }
    return 0;
}