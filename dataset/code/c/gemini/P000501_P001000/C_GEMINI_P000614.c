#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int k; scanf("%d", &k);
        int tmp = vals[k - 1]; vals[k - 1] = vals[n - k]; vals[n - k] = tmp;
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}