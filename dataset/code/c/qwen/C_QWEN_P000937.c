#include <stdio.h>
int main() {
    int n; long long k; scanf("%d%lld", &n, &k);
    long long a[n][n], res[n][n], temp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { scanf("%lld", &a[i][j]); res[i][j] = i==j?1:0; }
    while(k > 0) {
        if(k % 2 == 1) {
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) { long long s=0; for(int l=0; l<n; l++) s+=res[i][l]*a[l][j]; temp[i][j]=s; }
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) res[i][j]=temp[i][j];
        }
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) { long long s=0; for(int l=0; l<n; l++) s+=a[i][l]*a[l][j]; temp[i][j]=s; }
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j]=temp[i][j];
        k /= 2;
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) printf("%lld%c", res[i][j], j==n-1?'\n':' ');
    return 0;
}
