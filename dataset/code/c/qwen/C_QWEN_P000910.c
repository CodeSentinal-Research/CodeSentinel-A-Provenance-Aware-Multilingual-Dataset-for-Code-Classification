#include <stdio.h>
long long nPr(int n, int r) {
    long long res = 1;
    for(int i=0; i<r; i++) res *= (n - i);
    return res;
}
int main() {
    int n, r; scanf("%d%d", &n, &r);
    printf("%lld\n", nPr(n, r));
    return 0;
}
