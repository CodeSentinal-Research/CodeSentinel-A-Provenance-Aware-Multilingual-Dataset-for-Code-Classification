#include <stdio.h>
int main() {
    int n, q; scanf("%d%d", &n, &q);
    int a[n], prefix[n+1]; prefix[0]=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); prefix[i+1] = prefix[i] ^ a[i]; }
    while(q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", prefix[r+1] ^ prefix[l]);
    }
    return 0;
}
