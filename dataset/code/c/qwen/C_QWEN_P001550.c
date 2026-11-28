#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<=n-k; i++) {
        long long sum = 0;
        for(int j=1; j<k; j++) sum += abs(arr[i+j] - arr[i+j-1]);
        printf("%lld ", sum);
    }
    printf("\n");
    return 0;
}
