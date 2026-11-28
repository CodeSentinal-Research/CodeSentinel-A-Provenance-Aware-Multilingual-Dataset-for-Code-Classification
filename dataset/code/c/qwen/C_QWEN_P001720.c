#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n]; long long sum = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &val[i]); sum += val[i]; }
    printf("%lld\n", sum);
    return 0;
}
