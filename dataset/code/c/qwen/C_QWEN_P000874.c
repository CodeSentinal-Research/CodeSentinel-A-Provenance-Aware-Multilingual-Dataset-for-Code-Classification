#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int encoded[n-1];
    int total_xor = 0; for(int i=1; i<=n; i++) total_xor ^= i;
    int xor_odd = 0; for(int i=1; i<n-1; i+=2) xor_odd ^= encoded[i];
    int first = total_xor ^ xor_odd;
    int res[n]; res[0] = first;
    for(int i=0; i<n-1; i++) res[i+1] = res[i] ^ encoded[i];
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
