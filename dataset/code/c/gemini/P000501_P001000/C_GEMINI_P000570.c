#include <stdio.h>
#define MAX_N 100005
int q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &q[i]);
        int k; scanf("%d", &k);
        k %= n;
        for (int i = 0; i < n; i++) {
            printf("%d%s", q[(i + k) % n], i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}