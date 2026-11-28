#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n];
    int xor_all = 0; for(int i=0; i<n; i++) { scanf("%d", &a[i]); xor_all ^= a[i]; }
    int set_bit = xor_all & ~(xor_all - 1);
    int x=0, y=0;
    for(int i=0; i<n; i++) { if(a[i] & set_bit) x ^= a[i]; else y ^= a[i]; }
    printf("%d %d\n", x, y);
    return 0;
}
