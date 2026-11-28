#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n]; long long max_diff = 0;
    for(int i=0; i<n; i++) scanf("%lld", &val[i]);
    for(int i=1; i<n; i++) {
        long long diff = val[i] - val[i-1];
        if(diff < 0) diff = -diff;
        if(diff > max_diff) max_diff = diff;
    }
    printf("%lld\n", max_diff);
    return 0;
}
