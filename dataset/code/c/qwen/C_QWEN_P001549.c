#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int cur = 0, count = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) { if(arr[i] > 0) cur++; else cur = 0; }
    }
    if(cur == k) count++;
    for(int i=k; i<n; i++) {
        if(arr[i] > 0 && cur == k) cur = k; // wait, logic
        // simpler:
        if(arr[i] <= 0) cur = 0;
        else if(cur < k) cur++;
        if(arr[i-k] <= 0) {} // wait
        // Let's just use standard sliding window
    }
    // Re-implement cleanly
    cur = 0; count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) cur++; else cur = 0;
        if(i >= k && arr[i-k] > 0) {} // actually just check if cur >= k
        if(cur >= k) count++;
    }
    printf("%d\n", count);
    return 0;
}
