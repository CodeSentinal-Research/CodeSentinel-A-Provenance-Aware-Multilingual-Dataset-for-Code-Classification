#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int ok = 1;
    for(int i=0; i<n; i++) {
        int l = 2*i+1, r = 2*i+2;
        if(l < n && a[l] < a[i]) ok = 0;
        if(r < n && a[r] < a[i]) ok = 0;
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
