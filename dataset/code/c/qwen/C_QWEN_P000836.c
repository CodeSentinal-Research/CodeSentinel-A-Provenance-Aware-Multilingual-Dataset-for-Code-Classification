#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int pos[n]; for(int i=0; i<n; i++) scanf("%d", &pos[i]);
    qsort(pos, n, sizeof(int), cmp);
    int l=0, r=pos[n-1]-pos[0], ans=0;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int count=1, last=pos[0];
        for(int i=1; i<n; i++) { if(pos[i]-last>=mid) { count++; last=pos[i]; } }
        if(count>=m) { ans=mid; l=mid+1; } else r=mid-1;
    }
    printf("%d\n", ans);
    return 0;
}
