#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long max_sum = arr[0], curr = arr[0];
    for(int i=1; i<n; i++) {
        curr = curr > 0 ? curr + arr[i] : arr[i];
        if(curr > max_sum) max_sum = curr;
    }
    printf("%lld\n", max_sum);
    return 0;
}
