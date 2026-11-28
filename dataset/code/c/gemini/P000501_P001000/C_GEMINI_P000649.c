#include <stdio.h>
#define MAX_N 100005
int l1[MAX_N], l2[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &l1[i]);
        int m; scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &l2[i]);
        if (n != m) { printf("false\n"); return 0; }
        for (int i = 0; i < n; i++) {
            if (l1[i] != l2[i]) { printf("false\n"); return 0; }
        }
        printf("true\n");
    }
    return 0;
}