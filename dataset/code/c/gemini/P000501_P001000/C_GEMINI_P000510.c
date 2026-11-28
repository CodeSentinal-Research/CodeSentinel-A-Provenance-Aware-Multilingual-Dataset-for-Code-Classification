#include <stdio.h>
#define MAX_N 100005
int p[MAX_N], ans[MAX_N], st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { scanf("%d", &p[i]); ans[i] = p[i]; }
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && p[st[top]] >= p[i]) {
                ans[st[top--]] -= p[i];
            }
            st[++top] = i;
        }
        for (int i = 0; i < n; i++) printf("%d%s", ans[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}