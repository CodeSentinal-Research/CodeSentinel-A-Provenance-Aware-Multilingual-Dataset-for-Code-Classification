#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int price[n]; for(int i=0; i<n; i++) scanf("%d", &price[i]);
    qsort(price, n, sizeof(int), cmp);
    int l=0, r=price[n-1]-price[0], ans=0;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int count=1, last=price[0];
        for(int i=1; i<n; i++) { if(price[i]-last>=mid) { count++; last=price[i]; } }
        if(count>=k) { ans=mid; l=mid+1; } else r=mid-1;
    }
    printf("%d\n", ans);
    return 0;
}
