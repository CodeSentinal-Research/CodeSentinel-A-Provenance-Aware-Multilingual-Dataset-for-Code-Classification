#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) printf(" ");
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}