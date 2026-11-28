#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<=n-k; i++) {
        int mx = a[i];
        for(int j=1; j<k; j++) if(a[i+j] > mx) mx = a[i+j];
        printf("%d%c", mx, i==n-k?'\n':' ');
    }
    return 0;
}
