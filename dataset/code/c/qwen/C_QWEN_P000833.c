#include <stdio.h>
int main() {
    int n, students; scanf("%d%d", &n, &students);
    int pages[n]; long long total=0, max_p=0;
    for(int i=0; i<n; i++) { scanf("%d", &pages[i]); total+=pages[i]; if(pages[i]>max_p) max_p=pages[i]; }
    long long l=max_p, r=total, ans=total;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, s=1;
        for(int i=0; i<n; i++) { if(sum+pages[i]>mid) { s++; sum=pages[i]; } else sum+=pages[i]; }
        if(s<=students) { ans=mid; r=mid-1; } else l=mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
