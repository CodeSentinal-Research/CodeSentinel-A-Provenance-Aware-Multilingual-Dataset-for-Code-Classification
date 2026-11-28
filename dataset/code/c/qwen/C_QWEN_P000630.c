#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    if(k>n) printf("-1\n"); else printf("%d\n", vals[n-k]);
    return 0;
}
