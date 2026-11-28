#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int stations[n]; for(int i=0; i<n; i++) scanf("%d", &stations[i]);
    double l=0, r=stations[n-1]-stations[0], ans=0;
    while(r-l > 1e-6) {
        double mid=l+(r-l)/2;
        int count=0;
        for(int i=1; i<n; i++) count += (int)((stations[i]-stations[i-1])/mid);
        if(count<=k) { ans=mid; r=mid; } else l=mid;
    }
    printf("%.6f\n", ans);
    return 0;
}
