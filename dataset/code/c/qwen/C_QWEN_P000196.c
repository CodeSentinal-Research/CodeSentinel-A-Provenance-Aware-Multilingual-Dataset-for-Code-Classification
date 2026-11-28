#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    long long sum = 0, max_sum = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<k; i++) sum += arr[i];
    max_sum = sum;
    for(int i=k; i<n; i++) { sum += arr[i] - arr[i-k]; if(sum > max_sum) max_sum = sum; }
    printf("%lld\n", max_sum);
    return 0;
}
