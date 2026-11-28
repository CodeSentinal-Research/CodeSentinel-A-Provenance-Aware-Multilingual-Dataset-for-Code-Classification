#include <stdio.h>
#define MAX_N 10005
int target[MAX_N];
int main() {
    int m;
    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) scanf("%d", &target[i]);
        int n;
        scanf("%d", &n);
        int target_idx = 0;
        for (int i = 1; i <= n; i++) {
            if (target_idx == m) break;
            printf("Push\n");
            if (target[target_idx] == i) target_idx++;
            else printf("Pop\n");
        }
    }
    return 0;
}