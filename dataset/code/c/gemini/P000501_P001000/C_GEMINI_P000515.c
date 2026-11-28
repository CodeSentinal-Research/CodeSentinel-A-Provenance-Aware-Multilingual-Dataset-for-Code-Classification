#include <stdio.h>
#define MAX_N 100005
double p[MAX_N], s[MAX_N], ans[MAX_N];
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { scanf("%lf %lf", &p[i], &s[i]); ans[i] = -1.0; }
        int top = -1;
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0) {
                int j = st[top];
                if (s[i] <= s[j] || (ans[j] > 0 && (p[j] - p[i]) / (s[i] - s[j]) >= ans[j])) {
                    top--;
                } else {
                    break;
                }
            }
            if (top >= 0) {
                int j = st[top];
                ans[i] = (p[j] - p[i]) / (s[i] - s[j]);
            }
            st[++top] = i;
        }
        for (int i = 0; i < n; i++) printf("%.5f%s", ans[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}