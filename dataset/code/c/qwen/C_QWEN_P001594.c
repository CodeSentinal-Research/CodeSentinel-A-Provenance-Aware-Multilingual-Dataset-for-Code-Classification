#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); prefix[i+1] = prefix[i] + arr[i]; }
    for(int i=1; i<=n; i++) printf("%lld ", prefix[i]);
    printf("\n");
    return 0;
}
