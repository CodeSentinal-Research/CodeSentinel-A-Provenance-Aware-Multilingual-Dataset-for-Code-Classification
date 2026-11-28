#include <stdio.h>
#define MAX_N 100005
long long arr[MAX_N];
int prev_less[MAX_N], next_less[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        long long MOD = 1000000007;
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            prev_less[i] = (top >= 0) ? st[top] : -1;
            st[++top] = i;
        }
        top = -1;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] > arr[i]) top--;
            next_less[i] = (top >= 0) ? st[top] : n;
            st[++top] = i;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_less[i];
            long long right = next_less[i] - i;
            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}