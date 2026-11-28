#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    if(n <= 1) { printf("%d\n", n); return 0; }
    int up = 1, down = 1;
    for(int i=1; i<n; i++) {
        if(a[i] > a[i-1]) up = down + 1;
        else if(a[i] < a[i-1]) down = up + 1;
    }
    printf("%d\n", up > down ? up : down);
    return 0;
}
