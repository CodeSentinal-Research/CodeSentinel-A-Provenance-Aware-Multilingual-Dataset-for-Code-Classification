#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long orig = n, sum = 0;
    while(n > 0) { sum += n % 10; n /= 10; }
    printf("%s\n", orig % sum == 0 ? "true" : "false");
    return 0;
}
