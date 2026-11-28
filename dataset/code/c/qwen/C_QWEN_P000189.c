#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    long long total = 0, max_kadane = -2000000000LL, min_kadane = 2000000000LL, curr_max = 0, curr_min = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]); total += arr[i];
        curr_max = curr_max + arr[i] > arr[i] ? curr_max + arr[i] : arr[i];
        curr_min = curr_min + arr[i] < arr[i] ? curr_min + arr[i] : arr[i];
        if(curr_max > max_kadane) max_kadane = curr_max;
        if(curr_min < min_kadane) min_kadane = curr_min;
    }
    long long res = max_kadane;
    if(total - min_kadane > res && total != min_kadane) res = total - min_kadane;
    printf("%lld\n", res);
    return 0;
}
