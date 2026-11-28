#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int left[n], right[n];
    left[0] = arr[0]; right[n-1] = arr[n-1];
    for(int i=1; i<n; i++) left[i] = arr[i] > left[i-1] ? arr[i] : left[i-1];
    for(int i=n-2; i>=0; i--) right[i] = arr[i] > right[i+1] ? arr[i] : right[i+1];
    long long water = 0;
    for(int i=0; i<n; i++) water += (left[i] - arr[i]) < (right[i] - arr[i]) ? left[i] - arr[i] : right[i] - arr[i];
    printf("%lld\n", water);
    return 0;
}
