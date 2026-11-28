#include <stdio.h>
#include <stdlib.h>
struct Interval { int start, end, idx; };
int cmp(const void *a, const void *b) { return ((struct Interval*)a)->start - ((struct Interval*)b)->start; }
int main() {
    int n; scanf("%d", &n);
    struct Interval intervals[n];
    for(int i=0; i<n; i++) { scanf("%d%d", &intervals[i].start, &intervals[i].end); intervals[i].idx=i; }
    qsort(intervals, n, sizeof(struct Interval), cmp);
    int res[n];
    for(int i=0; i<n; i++) {
        int l=0, r=n-1, ans=-1;
        while(l<=r) { int mid=l+(r-l)/2; if(intervals[mid].start >= intervals[i].end) { ans=intervals[mid].idx; r=mid-1; } else l=mid+1; }
        res[intervals[i].idx] = ans;
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
