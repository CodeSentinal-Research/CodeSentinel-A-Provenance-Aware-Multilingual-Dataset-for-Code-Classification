#include <stdio.h>
int main() {
    int x; scanf("%d", &x);
    long long res = 0;
    while(x) { res = res * 10 + x % 10; x /= 10; }
    if(res > 2147483647 || res < -2147483648) printf("0\n");
    else printf("%lld\n", res);
    return 0;
}
