#include <stdio.h>
long long nCr(int n, int r) {
    if(r > n - r) r = n - r;
    long long res = 1;
    for(int i=0; i<r; i++) { res *= (n - i); res /= (i + 1); }
    return res;
}
int main() {
    int n, k; scanf("%d%d", &n, &k);
    double prob = (double)nCr(n, k) / (1LL << n);
    printf("%.6f\n", prob);
    return 0;
}
