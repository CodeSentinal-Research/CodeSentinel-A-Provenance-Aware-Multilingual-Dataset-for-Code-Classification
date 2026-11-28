#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    while (n != 1 && n != 4) {
        long long s = 0;
        while (n) {
            long long d = n % 10;
            s += d * d;
            n /= 10;
        }
        n = s;
    }
    printf("%s\n", n == 1 ? "YES" : "NO");
    return 0;
}
