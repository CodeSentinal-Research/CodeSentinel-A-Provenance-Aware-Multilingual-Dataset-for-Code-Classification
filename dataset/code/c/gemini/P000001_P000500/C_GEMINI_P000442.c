#include <stdio.h>
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v == target && idx == -1) idx = i;
        }
        printf("%d\n", idx);
    }
    return 0;
}