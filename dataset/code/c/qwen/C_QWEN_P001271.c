#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int ranges[n+1]; for(int i=0; i<=n; i++) scanf("%d", &ranges[i]);
    int max_reach[n+1]; for(int i=0; i<=n; i++) max_reach[i] = 0;
    for(int i=0; i<=n; i++) {
        int l = i - ranges[i] < 0 ? 0 : i - ranges[i];
        int r = i + ranges[i] > n ? n : i + ranges[i];
        if(max_reach[l] < r) max_reach[l] = r;
    }
    int taps = 0, end = 0, max_end = 0;
    for(int i=0; i<=n; i++) {
        if(i > max_end) { printf("-1\n"); return 0; }
        if(i > end) { taps++; end = max_end; }
        if(max_reach[i] > max_end) max_end = max_reach[i];
    }
    printf("%d\n", taps);
    return 0;
}
