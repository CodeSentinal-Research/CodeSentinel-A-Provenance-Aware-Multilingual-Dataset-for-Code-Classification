#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int prefix[n+1]; prefix[0] = 0;
    for(int i=0; i<n; i++) { int val; scanf("%d", &val); prefix[i+1] = prefix[i] ^ val; }
    int q; scanf("%d", &q);
    while(q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", prefix[r+1] ^ prefix[l]);
    }
    return 0;
}
