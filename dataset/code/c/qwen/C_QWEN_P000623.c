#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int idx=0;
    while(idx<n) {
        int end = idx+k-1 < n ? idx+k-1 : n-1;
        for(int i=end; i>=idx; i--) printf("%d ", vals[i]);
        idx = end+1;
        if(idx<n) { end = idx+k-1 < n ? idx+k-1 : n-1; for(int i=idx; i<=end; i++) printf("%d ", vals[i]); idx = end+1; }
    }
    printf("\n");
    return 0;
}
