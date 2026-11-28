#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) if(i!=n-k-1) printf("%d%c", vals[i], i==n-1?'\n':' ');
    printf("\n");
    return 0;
}
