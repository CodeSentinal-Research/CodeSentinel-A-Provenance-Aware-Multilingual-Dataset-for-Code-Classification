#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long min_sum = arr[0], curr = arr[0];
    for(int i=1; i<n; i++) {
        curr = curr < 0 ? curr + arr[i] : arr[i];
        if(curr < min_sum) min_sum = curr;
    }
    printf("%lld\n", min_sum);
    return 0;
}
