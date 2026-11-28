#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int pos, val; scanf("%d %d", &pos, &val);
        for (int i = n; i > pos; i--) vals[i] = vals[i-1];
        vals[pos] = val;
        for (int i = 0; i <= n; i++) printf("%d%s", vals[i], i == n ? "" : " ");
        printf("\n");
    }
    return 0;
}