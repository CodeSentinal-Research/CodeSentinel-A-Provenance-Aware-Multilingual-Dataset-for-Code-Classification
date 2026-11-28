#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); prefix[i+1] = prefix[i] + arr[i]; }
    int q; scanf("%d", &q);
    while(q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%.2f\n", (double)(prefix[r+1] - prefix[l]) / (r - l + 1));
    }
    return 0;
}
