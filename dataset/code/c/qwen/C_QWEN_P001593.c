#include <stdio.h>
int main() {
    int n; long long x; scanf("%d %lld", &n, &x);
    long long arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); prefix[i+1] = prefix[i] + arr[i]; }
    int ans = -1;
    for(int i=1; i<=n; i++) {
        if(prefix[i] > x) { ans = i; break; }
    }
    printf("%d\n", ans);
    return 0;
}
