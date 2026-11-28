#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long min1 = 2000000000LL, min2 = 2000000000LL;
    for(int i=0; i<n; i++) {
        if(arr[i] < min1) { min2 = min1; min1 = arr[i]; }
        else if(arr[i] < min2) min2 = arr[i];
    }
    printf("%lld\n", min1 * min2);
    return 0;
}
