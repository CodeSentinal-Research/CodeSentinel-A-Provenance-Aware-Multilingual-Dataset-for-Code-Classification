#include <stdio.h>
#define MAX_N 100005
int t[MAX_N], ans[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { scanf("%d", &t[i]); ans[i] = 0; }
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && t[st[top]] < t[i]) {
                int prev = st[top--];
                ans[prev] = i - prev;
            }
            st[++top] = i;
        }
        for (int i = 0; i < n; i++) {
            printf("%d%s", ans[i], i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}