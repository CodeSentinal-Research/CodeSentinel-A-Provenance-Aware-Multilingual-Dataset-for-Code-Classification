#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long max_sum = arr[0], curr = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) curr += arr[i]; else curr = arr[i];
        if(curr > max_sum) max_sum = curr;
    }
    printf("%lld\n", max_sum);
    return 0;
}
