#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int a[m], b[n];
    for(int i=0; i<m; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int first = 1;
    for(int i=0; i<m; i++) {
        int dup = 0;
        for(int k=0; k<i; k++) if(a[k] == a[i]) { dup = 1; break; }
        if(!dup) { if(!first) printf(" "); printf("%d", a[i]); first=0; }
    }
    for(int i=0; i<n; i++) {
        int dup = 0;
        for(int k=0; k<i; k++) if(b[k] == b[i]) { dup = 1; break; }
        if(dup) continue;
        int inA = 0;
        for(int j=0; j<m; j++) if(b[i] == a[j]) { inA = 1; break; }
        if(!inA) { if(!first) printf(" "); printf("%d", b[i]); first=0; }
    }
    printf("\n");
    return 0;
}
