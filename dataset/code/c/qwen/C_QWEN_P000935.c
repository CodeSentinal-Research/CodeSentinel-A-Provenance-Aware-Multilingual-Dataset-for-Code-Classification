#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n][n], sum = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<n; i++) sum += a[i][i] + a[i][n-1-i];
    if(n % 2 == 1) sum -= a[n/2][n/2];
    printf("%lld\n", sum);
    return 0;
}
