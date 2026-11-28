#include <stdio.h>
int main() {
    int n; long long total; scanf("%d%lld", &n, &total);
    int time[n]; for(int i=0; i<n; i++) scanf("%d", &time[i]);
    long long l = 1, r = 1000000000000000000LL, ans = r;
    while(l <= r) {
        long long mid = l + (r-l)/2;
        long long trips = 0;
        for(int i=0; i<n; i++) trips += mid / time[i];
        if(trips >= total) { ans = mid; r = mid-1; }
        else l = mid+1;
    }
    printf("%lld\n", ans);
    return 0;
}
