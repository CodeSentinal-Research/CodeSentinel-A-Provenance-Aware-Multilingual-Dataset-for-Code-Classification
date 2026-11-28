#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int prev = -1, first = 1;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if (first || x != prev) {
                if (!first) printf(" ");
                printf("%d", x);
                prev = x;
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}