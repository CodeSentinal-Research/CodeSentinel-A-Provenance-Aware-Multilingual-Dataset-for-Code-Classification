#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int ok = 1;
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        int prev = -1;
        for(int i=start; i<=end; i++) {
            if(level % 2 == 1) { // even level 0-indexed -> odd values
                if(arr[i] % 2 == 0 || (prev != -1 && arr[i] <= prev)) { ok = 0; break; }
            } else {
                if(arr[i] % 2 != 0 || (prev != -1 && arr[i] >= prev)) { ok = 0; break; }
            }
            prev = arr[i];
        }
        start = end + 1;
        level *= 2;
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
