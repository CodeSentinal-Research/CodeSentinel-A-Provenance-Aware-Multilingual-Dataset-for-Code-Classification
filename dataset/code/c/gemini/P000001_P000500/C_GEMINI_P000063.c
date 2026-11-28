#include <stdio.h>
#include <stdbool.h>
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
int main() {
    int l, r;
    if (scanf("%d %d", &l, &r) == 2) {
        int first = 1;
        for (int i = l; i <= r; i++) {
            if (is_prime(i)) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}