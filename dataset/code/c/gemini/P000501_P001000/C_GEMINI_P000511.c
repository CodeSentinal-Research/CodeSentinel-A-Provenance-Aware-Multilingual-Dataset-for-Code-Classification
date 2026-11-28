#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], ans[MAX_N], st[MAX_N * 2];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); ans[i] = -1; }
        int top = -1;
        for (int i = 0; i < 2 * n; i++) {
            int val = nums[i % n];
            while (top >= 0 && nums[st[top]] < val) {
                ans[st[top--]] = val;
            }
            if (i < n) st[++top] = i;
        }
        for (int i = 0; i < n; i++) printf("%d%s", ans[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}