#include <stdio.h>
int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int idx=0;
    while(idx<n) {
        int skip = idx+m < n ? idx+m : n;
        for(int i=idx; i<skip; i++) printf("%d ", vals[i]);
        idx = skip + k;
    }
    printf("\n");
    return 0;
}
