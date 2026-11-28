#include <stdio.h>
long long nCr(int n, int r) {
    if(r > n - r) r = n - r;
    long long res = 1;
    for(int i=0; i<r; i++) { res *= (n - i); res /= (i + 1); }
    return res;
}
int main() {
    int n, r; scanf("%d%d", &n, &r);
    printf("%lld\n", nCr(n, r));
    return 0;
}
