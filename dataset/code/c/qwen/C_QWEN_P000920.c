#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int max_d = 0, min_d = 9;
    if(n == 0) { printf("0 0\n"); return 0; }
    while(n > 0) { int d = n % 10; if(d > max_d) max_d = d; if(d < min_d) min_d = d; n /= 10; }
    printf("%d %d\n", max_d, min_d);
    return 0;
}
