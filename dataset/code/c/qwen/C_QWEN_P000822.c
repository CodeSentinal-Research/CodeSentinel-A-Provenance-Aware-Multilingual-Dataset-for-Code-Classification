#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k, x; scanf("%d%d%d", &n, &k, &x);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int l=0, r=n-k;
    while(l<r) {
        int mid=l+(r-l)/2;
        if(x-a[mid] > a[mid+k]-x) l=mid+1; else r=mid;
    }
    for(int i=l; i<l+k; i++) printf("%d%c", a[i], i==l+k-1?'\n':' ');
    return 0;
}
