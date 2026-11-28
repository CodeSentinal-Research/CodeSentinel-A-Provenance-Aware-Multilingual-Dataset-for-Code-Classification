#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long prod = 1;
    if(n == 0) prod = 0;
    while(n > 0) { prod *= n % 10; n /= 10; }
    printf("%lld\n", prod);
    return 0;
}
