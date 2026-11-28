#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int a[n], b[m], res[n+m], i=0, j=0, k=0;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    while(i<n && j<m) {
        if(a[i]<b[j]) res[k++]=a[i++]; else res[k++]=b[j++];
    }
    while(i<n) res[k++]=a[i++];
    while(j<m) res[k++]=b[j++];
    for(int i=0; i<k; i++) printf("%d%c", res[i], i==k-1?'\n':' ');
    return 0;
}
