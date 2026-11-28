#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long count = 0, cur = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) { cur++; }
        else { cur = 1; }
        count += cur;
    }
    printf("%lld\n", count);
    return 0;
}
