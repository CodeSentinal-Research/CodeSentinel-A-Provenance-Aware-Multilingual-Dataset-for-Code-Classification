#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    long long sq = n * n, sum = 0;
    while(sq > 0) { sum += sq % 10; sq /= 10; }
    printf("%s\n", sum == n ? "true" : "false");
    return 0;
}
