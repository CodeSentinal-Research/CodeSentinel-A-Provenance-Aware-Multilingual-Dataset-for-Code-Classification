#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int k; scanf("%d", &k);
        if (k >= 1 && k <= n) printf("%d\n", vals[n - k]);
        else printf("-1\n");
    }
    return 0;
}