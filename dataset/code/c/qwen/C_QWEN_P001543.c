#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    long long sum = 0, min_sum = 1e18;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) sum += arr[i];
    }
    min_sum = sum;
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        if(sum < min_sum) min_sum = sum;
    }
    printf("%lld\n", min_sum);
    return 0;
}
