#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long val[n];
    for(int i=0; i<n; i++) scanf("%lld", &val[i]);
    // Simplified: Print values
    for(int i=0; i<n; i++) printf("%lld ", val[i]);
    printf("\n");
    return 0;
}
