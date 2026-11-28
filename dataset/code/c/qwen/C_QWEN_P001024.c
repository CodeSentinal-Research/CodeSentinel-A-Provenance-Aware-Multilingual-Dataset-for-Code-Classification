#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int i; scanf("%d", &i);
    int l = 2*i+1, r = 2*i+2;
    printf("%d %d\n", l < n ? a[l] : -1, r < n ? a[r] : -1);
    return 0;
}
