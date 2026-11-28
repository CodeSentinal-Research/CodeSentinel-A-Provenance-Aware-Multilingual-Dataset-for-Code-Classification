#include <stdio.h>
long long sum_rec(int n) {
    if (n <= 0) return 0;
    return n + sum_rec(n - 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", sum_rec(n));
    }
    return 0;
}