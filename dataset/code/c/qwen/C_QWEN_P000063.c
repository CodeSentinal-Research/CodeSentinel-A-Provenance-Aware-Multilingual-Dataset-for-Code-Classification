#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int main() {
    int l, r, f = 1;
    scanf("%d %d", &l, &r);
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            if (!f) printf(" ");
            printf("%d", i);
            f = 0;
        }
    }
    printf("\n");
    return 0;
}
