#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int count = 0;
    if(n == 0) count = 1;
    while(n > 0) { count++; n /= 10; }
    printf("%d\n", count);
    return 0;
}
