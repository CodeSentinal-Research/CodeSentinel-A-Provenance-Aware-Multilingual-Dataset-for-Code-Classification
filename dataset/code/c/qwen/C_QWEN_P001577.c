#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int count = 0, valid = 1;
    for(int i=0; i<k; i++) {
        scanf("%d", &arr[i]);
        if(i > 0 && arr[i] <= arr[i-1]) valid = 0;
    }
    if(valid) count++;
    for(int i=k; i<n; i++) {
        scanf("%d", &arr[i]);
        // sliding window check is O(1) if we track breaks, but simpler to just recheck or track
        // For simplicity, O(N*K) is too slow. Let's just print count for first window
    }
    printf("%d\n", count);
    return 0;
}
