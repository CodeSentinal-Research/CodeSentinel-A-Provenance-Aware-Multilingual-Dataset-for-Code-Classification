#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int idx=0, grp=1;
    while(idx<n) {
        int end = idx+grp-1 < n ? idx+grp-1 : n-1;
        if((end-idx+1)%2==0) { for(int i=end; i>=idx; i--) printf("%d ", vals[i]); }
        else { for(int i=idx; i<=end; i++) printf("%d ", vals[i]); }
        idx = end+1; grp++;
    }
    printf("\n");
    return 0;
}
