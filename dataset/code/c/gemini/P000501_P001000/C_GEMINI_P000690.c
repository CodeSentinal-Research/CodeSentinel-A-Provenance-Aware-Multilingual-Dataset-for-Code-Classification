#include <stdio.h>
void print_bin(long long n) {
    if (n == 0) return;
    print_bin(n / 2);
    printf("%lld", n % 2);
}
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        if (n == 0) printf("0\n");
        else { print_bin(n); printf("\n"); }
    }
    return 0;
}