#include <stdio.h>
int main() {
    int n, g; scanf("%d %d", &n, &g); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int grps[g]; for(int i=0; i<g; i++) scanf("%d", &grps[i]);
    int idx=0;
    for(int i=0; i<g && idx<n; i++) {
        int sz = grps[i];
        if(idx+sz > n) { for(int j=idx; j<n; j++) printf("%d ", vals[j]); idx=n; }
        else { for(int j=idx+sz-1; j>=idx; j--) printf("%d ", vals[j]); idx+=sz; }
    }
    printf("\n");
    return 0;
}
