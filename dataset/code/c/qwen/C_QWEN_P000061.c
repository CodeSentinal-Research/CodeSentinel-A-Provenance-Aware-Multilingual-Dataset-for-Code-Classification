#include <stdio.h>

int main() {
    long long n, c = 0;
    scanf("%lld", &n);
    if (n == 0) c = 0;
    while (n > 0) {
        if ((n % 10) % 2 != 0) c++;
        n /= 10;
    }
    printf("%lld\n", c);
    return 0;
}
