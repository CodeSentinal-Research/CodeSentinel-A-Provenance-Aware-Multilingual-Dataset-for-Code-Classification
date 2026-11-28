#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int even = 0, odd = 0;
    if(n == 0) even = 1;
    while(n > 0) { int d = n % 10; if(d % 2 == 0) even++; else odd++; n /= 10; }
    printf("%d %d\n", even, odd);
    return 0;
}
