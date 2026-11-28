#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    long long a[n][m];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) printf("%lld%c", a[j][i], j==n-1?'\n':' ');
    return 0;
}
