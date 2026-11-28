#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long arr[n], total = 0;
    for(int i=0; i<n; i++) { scanf("%lld", &arr[i]); total += arr[i]; }
    long long left = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        if(left == total - left - arr[i]) count++;
        left += arr[i];
    }
    printf("%d\n", count);
    return 0;
}
