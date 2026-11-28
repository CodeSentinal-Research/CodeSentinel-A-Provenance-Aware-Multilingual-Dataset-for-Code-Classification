#include <stdio.h>

int main(void) {
    int n;
    long long a = 0, b = 1;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld%s", a, (i == n - 1) ? "\n" : " ");
        long long next = a + b;
        a = b;
        b = next;
    }
    if (n <= 0) printf("\n");

    return 0;
}
