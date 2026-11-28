#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, p; scanf("%d%d", &n, &p);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int l=0, r=a[n-1]-a[0], ans=r;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int count=0, last=-1000000000;
        for(int i=0; i<n; i++) { if(a[i]-last>=mid) { count++; last=a[i]; } }
        if(count>=p) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%d\n", ans);
    return 0;
}
