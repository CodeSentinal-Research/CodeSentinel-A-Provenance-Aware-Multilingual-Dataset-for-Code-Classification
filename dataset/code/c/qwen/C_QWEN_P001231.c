#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int g[n], s[m];
    for(int i=0; i<n; i++) scanf("%d", &g[i]);
    for(int i=0; i<m; i++) scanf("%d", &s[i]);
    qsort(g, n, sizeof(int), cmp);
    qsort(s, m, sizeof(int), cmp);
    int i=0, j=0, count=0;
    while(i<n && j<m) {
        if(s[j] >= g[i]) { count++; i++; j++; }
        else j++;
    }
    printf("%d\n", count);
    return 0;
}
