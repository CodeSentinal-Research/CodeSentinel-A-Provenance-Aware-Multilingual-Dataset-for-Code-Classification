#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long phi[n+1];
    for(int i=0; i<=n; i++) phi[i] = i;
    for(int i=2; i<=n; i++) {
        if(phi[i] == i) {
            for(int j=i; j<=n; j+=i) phi[j] -= phi[j] / i;
        }
    }
    long long sum = 0;
    for(int i=1; i<=n; i++) sum += phi[i];
    printf("%lld\n", sum);
    return 0;
}
