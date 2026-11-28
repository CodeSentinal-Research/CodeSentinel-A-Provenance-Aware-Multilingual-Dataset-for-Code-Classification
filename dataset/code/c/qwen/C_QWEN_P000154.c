#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    long long sum = 0, sq_sum = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); sum += arr[i]; sq_sum += (long long)arr[i]*arr[i]; }
    long long exp_sum = (long long)n*(n+1)/2;
    long long exp_sq = (long long)n*(n+1)*(2*n+1)/6;
    long long diff = exp_sum - sum;
    long long sum_diff = exp_sq - sq_sum;
    long long rep = (sum_diff / diff + diff) / 2;
    long long miss = rep - diff;
    printf("%lld %lld\n", miss, rep);
    return 0;
}
