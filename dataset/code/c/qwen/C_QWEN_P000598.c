#include <stdio.h>
int main() {
    int n, l, r; scanf("%d %d %d", &n, &l, &r);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    l--; r--;
    while(l<r) { int t=vals[l]; vals[l]=vals[r]; vals[r]=t; l++; r--; }
    for(int i=0; i<n; i++) printf("%d%c", vals[i], i==n-1?'\n':' ');
    return 0;
}
