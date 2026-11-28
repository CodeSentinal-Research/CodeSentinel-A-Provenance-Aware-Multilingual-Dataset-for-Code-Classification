#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n]; long long min_sum = 1e18;
    for(int i=0; i<n; i++) { scanf("%lld", &val[i]); if(val[i] < min_sum) min_sum = val[i]; }
    printf("%lld\n", min_sum);
    return 0;
}
