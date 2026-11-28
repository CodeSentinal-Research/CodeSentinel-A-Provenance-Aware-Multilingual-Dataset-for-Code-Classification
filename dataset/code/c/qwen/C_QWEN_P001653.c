#include <stdio.h>
#include <limits.h>

long long maxPath(int *arr, int i, int n, long long *max_sum) {
    if(i >= n || arr[i] == -1) return 0;
    long long l = maxPath(arr, 2*i+1, n, max_sum);
    long long r = maxPath(arr, 2*i+2, n, max_sum);
    long long single = arr[i] + (l > r ? l : r);
    long long top = arr[i] + l + r;
    if(top > *max_sum) *max_sum = top;
    return single > 0 ? single : 0;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long max_sum = LLONG_MIN;
    maxPath(arr, 0, n, &max_sum);
    printf("%lld\n", max_sum);
    return 0;
}
