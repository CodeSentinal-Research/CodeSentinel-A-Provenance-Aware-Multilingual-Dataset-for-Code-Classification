#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long arr[n], res[n];
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    long long left[n], right[n];
    left[0] = 1;
    for(int i=1; i<n; i++) left[i] = left[i-1] * arr[i-1];
    right[n-1] = 1;
    for(int i=n-2; i>=0; i--) right[i] = right[i+1] * arr[i+1];
    for(int i=0; i<n; i++) {
        res[i] = left[i] * right[i];
        printf("%lld%c", res[i], i==n-1?'\n':' ');
    }
    return 0;
}
