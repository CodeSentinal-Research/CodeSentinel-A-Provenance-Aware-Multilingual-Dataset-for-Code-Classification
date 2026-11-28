#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 1, cur = 1;
    for(int i=1; i<n; i++) {
        if((arr[i] > arr[i-1] && cur > 0) || (arr[i] < arr[i-1] && cur < 0)) {
            cur = arr[i] > arr[i-1] ? 1 : -1;
            // Actually simpler logic:
        }
    }
    // Simplified O(N) logic
    int up=1, down=1, ans=1;
    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) { up = down + 1; down = 1; }
        else if(arr[i] < arr[i-1]) { down = up + 1; up = 1; }
        else { up = 1; down = 1; }
        if(up > ans) ans = up;
        if(down > ans) ans = down;
    }
    printf("%d\n", ans);
    return 0;
}
