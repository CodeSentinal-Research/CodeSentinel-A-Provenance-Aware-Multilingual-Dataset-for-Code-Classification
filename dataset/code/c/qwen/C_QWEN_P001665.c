#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int ok = 1;
    for(int i=0; i<n; i++) {
        int l = 2*i+1, r = 2*i+2;
        int has_l = l < n && arr[l] != -1;
        int has_r = r < n && arr[r] != -1;
        if(has_l != has_r) { ok = 0; break; }
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
