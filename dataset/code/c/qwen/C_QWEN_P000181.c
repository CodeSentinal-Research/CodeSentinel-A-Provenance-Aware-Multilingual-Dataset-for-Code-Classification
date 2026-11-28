#include <stdio.h>
int main() {
    int n, l, m; scanf("%d %d %d", &n, &l, &m);
    int arr[n];
    long long sum[n+1]; sum[0] = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); sum[i+1] = sum[i] + arr[i]; }
    long long max_sum = 0;
    for(int i=l; i<=n-m; i++) {
        long long s1 = sum[i] - sum[i-l];
        long long s2 = sum[i+m] - sum[i];
        if(s1 + s2 > max_sum) max_sum = s1 + s2;
    }
    printf("%lld\n", max_sum);
    return 0;
}
