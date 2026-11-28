#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int h = 0;
    while((1LL << (h+1)) - 1 < n) h++;
    printf("%d\n", h);
    return 0;
}
