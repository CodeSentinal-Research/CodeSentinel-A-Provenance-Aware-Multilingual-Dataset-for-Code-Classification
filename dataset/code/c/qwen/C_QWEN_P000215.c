#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    long long arr[n], sum=0, max_sum=0;
    for(int i=0; i<k; i++) { scanf("%lld", &arr[i]); sum += arr[i]; }
    max_sum = sum;
    for(int i=k; i<n; i++) { scanf("%lld", &arr[i]); sum += arr[i] - arr[i-k]; if(sum > max_sum) max_sum = sum; }
    printf("%.5f\n", (double)max_sum / k);
    return 0;
}
