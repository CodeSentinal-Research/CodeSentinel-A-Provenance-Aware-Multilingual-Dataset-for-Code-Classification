#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int t = vals[k-1]; vals[k-1] = vals[n-k]; vals[n-k] = t;
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
