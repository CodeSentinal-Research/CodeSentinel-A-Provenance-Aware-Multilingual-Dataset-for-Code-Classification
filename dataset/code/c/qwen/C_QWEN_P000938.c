#include <stdio.h>
int main() {
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    long long a[n][m], b[m][p];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<m; i++) for(int j=0; j<p; j++) scanf("%lld", &b[i][j]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            long long sum = 0;
            for(int k=0; k<m; k++) if(a[i][k] && b[k][j]) sum += a[i][k] * b[k][j];
            printf("%lld%c", sum, j==p-1?'\n':' ');
        }
    }
    return 0;
}
