#include <stdio.h>
#include <stdbool.h>
bool is_prime_rec(long long n, long long d) {
    if (n <= 1) return false;
    if (d * d > n) return true;
    if (n % d == 0) return false;
    return is_prime_rec(n, d + 1);
}
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%s\n", is_prime_rec(n, 2) ? "true" : "false");
    }
    return 0;
}