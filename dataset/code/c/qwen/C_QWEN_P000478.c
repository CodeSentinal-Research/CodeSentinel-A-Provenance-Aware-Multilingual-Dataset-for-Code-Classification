#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, c; scanf("%d %d", &n, &c);
    int stalls[1000];
    for(int i=0; i<n; i++) scanf("%d", &stalls[i]);
    qsort(stalls, n, sizeof(int), cmp);
    int l=0, r=stalls[n-1]-stalls[0], res=0;
    while(l<=r) {
        int mid = l+(r-l)/2;
        int count=1, last=stalls[0];
        for(int i=1; i<n; i++) {
            if(stalls[i]-last>=mid) { count++; last=stalls[i]; }
        }
        if(count>=c) { res=mid; l=mid+1; } else r=mid-1;
    }
    printf("%d\n", res);
    return 0;
}
