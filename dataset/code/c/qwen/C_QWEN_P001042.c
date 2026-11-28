#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int leaves = n - n/2;
    for(int i=n/2; i<n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
    return 0;
}
