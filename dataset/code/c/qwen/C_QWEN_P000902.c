#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int q; scanf("%d", &q);
    while(q--) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        int count = 0;
        for(int i=l; i<=r; i++) if(a[i] % x == 0) count++;
        printf("%d\n", count);
    }
    return 0;
}
