#include <stdio.h>
#define MAX_N 100005
long long heights[MAX_N];
int st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%lld", &heights[i]);
        heights[n] = 0;
        int top = 0;
        st[0] = -1;
        long long max_area = 0;
        for (int i = 0; i <= n; i++) {
            while (top > 0 && heights[st[top]] >= heights[i]) {
                long long h = heights[st[top--]];
                long long w = i - st[top] - 1;
                if (h * w > max_area) max_area = h * w;
            }
            st[++top] = i;
        }
        printf("%lld\n", max_area);
    }
    return 0;
}