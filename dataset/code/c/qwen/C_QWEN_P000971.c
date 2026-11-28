#include <stdio.h>
int main() {
    long long A, B, F0, F1; int n;
    scanf("%lld%lld%lld%lld%d", &A, &B, &F0, &F1, &n);
    long long prev = F0, curr = F1;
    for(int i=2; i<=n; i++) { long long t = (A * curr + B * prev); prev = curr; curr = t; }
    printf("%lld\n", n == 0 ? F0 : curr);
    return 0;
}
