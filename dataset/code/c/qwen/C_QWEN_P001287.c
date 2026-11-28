#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l = 0, r = 1000000000, ans = 0;
    while(l <= r) {
        int mid = l + (r-l)/2;
        int sum = 0, pieces = 0;
        for(int i=0; i<n; i++) {
            sum += a[i];
            if(sum >= mid) { pieces++; sum = 0; }
        }
        if(pieces >= k+1) { ans = mid; l = mid+1; }
        else r = mid-1;
    }
    printf("%d\n", ans);
    return 0;
}
