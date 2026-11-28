#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            printf("%d%s", x, (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}