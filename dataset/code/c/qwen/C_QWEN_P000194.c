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
        if(dup) continue;
        for(int j=0; j<n; j++) {
            if(a[i] == b[j]) {
                if(!first) printf(" ");
                printf("%d", a[i]);
                first = 0;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
