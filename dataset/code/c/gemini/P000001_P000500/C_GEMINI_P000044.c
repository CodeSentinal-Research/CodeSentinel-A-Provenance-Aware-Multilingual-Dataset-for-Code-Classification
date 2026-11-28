#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = n; i >= 1; i--) {
            if (i < n) printf(" ");
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}