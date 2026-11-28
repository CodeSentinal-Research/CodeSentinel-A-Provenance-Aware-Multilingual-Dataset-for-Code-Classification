#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n][n]; int ok = 1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lld", &a[i][j]);
    for(int i=0; i<n && ok; i++) for(int j=0; j<n && ok; j++) if(a[i][j] != a[j][i]) ok = 0;
    printf("%s\n", ok ? "true" : "false");
    return 0;
}
