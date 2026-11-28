#include <stdio.h>
int main() {
    int n, m; scanf("%d%d", &n, &m);
    long long a[n][m], b[n][m];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%lld", &b[i][j]);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) printf("%lld%c", a[i][j] + b[i][j], j==m-1?'\n':' ');
    return 0;
}
