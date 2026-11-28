#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int ones[n], count=0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]==1) ones[count++] = i; }
    if(k == 0) { printf("0\n"); return 0; }
    long long min_swaps = 1e18;
    for(int i=0; i<=count-k; i++) {
        long long swaps = 0;
        int mid = ones[i + k/2];
        for(int j=i; j<i+k; j++) swaps += abs(ones[j] - mid) - abs(j - i);
        if(swaps < min_swaps) min_swaps = swaps;
    }
    printf("%lld\n", min_swaps);
    return 0;
}
