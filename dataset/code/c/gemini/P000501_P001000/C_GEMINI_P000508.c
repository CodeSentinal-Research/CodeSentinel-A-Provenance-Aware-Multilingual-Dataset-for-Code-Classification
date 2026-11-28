#include <stdio.h>
#define MAX_N 100005
int h[MAX_N], ans[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &h[i]);
        int top = -1;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (top >= 0 && st[top] < h[i]) {
                top--;
                count++;
            }
            if (top >= 0) count++;
            ans[i] = count;
            st[++top] = h[i];
        }
        for (int i = 0; i < n; i++) printf("%d%s", ans[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}