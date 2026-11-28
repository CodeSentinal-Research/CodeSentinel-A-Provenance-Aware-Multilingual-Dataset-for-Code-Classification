#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long a[n][n]; int ok = 1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        scanf("%lld", &a[i][j]);
        if(i == j && a[i][j] != 1) ok = 0;
        if(i != j && a[i][j] != 0) ok = 0;
    }
    printf("%s\n", ok ? "true" : "false");
    return 0;
}
