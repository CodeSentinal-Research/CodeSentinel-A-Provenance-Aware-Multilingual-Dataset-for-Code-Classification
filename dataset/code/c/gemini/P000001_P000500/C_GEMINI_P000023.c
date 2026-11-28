#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%lld", a);
            long long next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    }
    return 0;
}