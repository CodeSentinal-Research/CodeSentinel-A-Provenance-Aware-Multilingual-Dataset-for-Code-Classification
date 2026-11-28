#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int l=0, r=n-1, pal=1;
    while(l<r) { if(vals[l]!=vals[r]) { pal=0; break; } l++; r--; }
    printf("%s\n", pal ? "true" : "false");
    return 0;
}
