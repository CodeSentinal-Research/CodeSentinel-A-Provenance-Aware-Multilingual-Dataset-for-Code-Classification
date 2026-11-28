#include <stdio.h>
int main() {
    int n, q; scanf("%d%d", &n, &q);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int valid = 1;
    for(int i=0; i<n; i++) {
        int l = 2*i+1, r = 2*i+2;
        if(l < n && a[l] < a[i]) valid = 0;
        if(r < n && a[r] < a[i]) valid = 0;
    }
    while(q--) {
        int idx, val; scanf("%d%d", &idx, &val);
        a[idx] = val;
    }
    for(int i=0; i<n; i++) {
        int l = 2*i+1, r = 2*i+2;
        if(l < n && a[l] < a[i]) valid = 0;
        if(r < n && a[r] < a[i]) valid = 0;
    }
    printf("%s\n", valid ? "VALID" : "INVALID");
    return 0;
}
