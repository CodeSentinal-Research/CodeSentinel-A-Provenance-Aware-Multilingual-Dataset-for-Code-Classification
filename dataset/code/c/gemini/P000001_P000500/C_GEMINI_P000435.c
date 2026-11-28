#include <stdio.h>
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            if (v == target) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}