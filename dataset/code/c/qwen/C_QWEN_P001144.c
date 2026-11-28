#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dp[n], len = 0;
    for(int i=0; i<n; i++) {
        int l = 0, r = len;
        while(l < r) { int mid = (l+r)/2; if(dp[mid] < a[i]) l = mid + 1; else r = mid; }
        dp[l] = a[i];
        if(l == len) len++;
    }
    printf("%d\n", len);
    return 0;
}
