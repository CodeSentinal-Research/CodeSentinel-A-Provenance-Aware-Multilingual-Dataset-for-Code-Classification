#include <stdio.h>
long long fact_rec(int n) {
    if (n <= 1) return 1;
    return n * fact_rec(n - 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", fact_rec(n));
    }
    return 0;
}