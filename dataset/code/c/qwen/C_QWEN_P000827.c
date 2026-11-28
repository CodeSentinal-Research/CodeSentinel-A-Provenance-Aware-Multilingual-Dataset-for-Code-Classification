#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int houses[n], heaters[m];
    for(int i=0; i<n; i++) scanf("%d", &houses[i]);
    for(int i=0; i<m; i++) scanf("%d", &heaters[i]);
    qsort(houses, n, sizeof(int), cmp);
    qsort(heaters, m, sizeof(int), cmp);
    int max_r = 0;
    for(int i=0; i<n; i++) {
        int l=0, r=m-1, closest=heaters[0];
        while(l<=r) { int mid=l+(r-l)/2; if(heaters[mid]==houses[i]) { closest=houses[i]; break; } else if(heaters[mid]<houses[i]) { closest=heaters[mid]; l=mid+1; } else { closest=heaters[mid]; r=mid-1; } }
        int dist = abs(houses[i]-closest);
        if(dist>max_r) max_r=dist;
    }
    printf("%d\n", max_r);
    return 0;
}
