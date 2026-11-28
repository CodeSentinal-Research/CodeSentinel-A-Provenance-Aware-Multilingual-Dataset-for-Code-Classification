#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n]; long long max_sum = -1e18;
    for(int i=0; i<n; i++) { scanf("%lld", &val[i]); if(val[i] > max_sum) max_sum = val[i]; }
    printf("%lld\n", max_sum);
    return 0;
}
