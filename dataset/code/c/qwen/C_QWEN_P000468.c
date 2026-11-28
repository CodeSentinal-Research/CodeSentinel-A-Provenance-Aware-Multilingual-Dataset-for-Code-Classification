#include <stdio.h>
int main() {
    int m, n, k; scanf("%d %d %d", &m, &n, &k);
    int a[500], b[500];
    for(int i=0; i<m; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int i=0, j=0, count=0, res=0;
    while(count < k) {
        res = (i<m && (j>=n || a[i]<b[j])) ? a[i++] : b[j++];
        count++;
    }
    printf("%d\n", res);
    return 0;
}
