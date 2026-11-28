#include <stdio.h>

int main() {
    int n, a = 0, b = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a);
        int t = a + b;
        a = b;
        b = t;
    }
    printf("\n");
    return 0;
}
