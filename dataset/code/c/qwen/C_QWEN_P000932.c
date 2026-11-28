#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n][n], trace = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<n; i++) trace += a[i][i];
    printf("%lld\n", trace);
    return 0;
}
