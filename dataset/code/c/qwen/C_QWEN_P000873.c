#include <stdio.h>
int main() {
    int n, first; scanf("%d%d", &n, &first);
    int encoded[n]; for(int i=0; i<n; i++) scanf("%d", &encoded[i]);
    int res[n]; res[0] = first;
    for(int i=0; i<n; i++) res[i+1] = res[i] ^ encoded[i];
    for(int i=0; i<=n; i++) printf("%d%c", res[i], i==n?'\n':' ');
    return 0;
}
