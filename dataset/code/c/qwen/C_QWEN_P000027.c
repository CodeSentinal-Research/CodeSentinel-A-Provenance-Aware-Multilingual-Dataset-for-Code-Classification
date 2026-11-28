#include <stdio.h>

int main() {
    long long n, c = 0;
    scanf("%lld", &n);
    if (n == 0) c = 1;
    while (n > 0) {
        c++;
        n /= 10;
    }
    printf("%lld\n", c);
    return 0;
}
