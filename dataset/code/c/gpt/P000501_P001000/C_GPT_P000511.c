#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Next Greater Element II */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long st[200000], ans[200000];
    int top = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (top > 0 && st[top - 1] <= a[i]) top--;
        ans[i] = top ? st[top - 1] : -1;
        st[top++] = a[i];
    }
    for (int i = 0; i < n; i++) printf("%lld%s", ans[i], i + 1 == n ? "\n" : " ");
    if (n == 0) printf("\n");


    return 0;
}
