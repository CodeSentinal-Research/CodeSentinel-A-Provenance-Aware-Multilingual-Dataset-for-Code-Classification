#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d %d", &n, &m); int a[n], b[m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    int all[n+m]; for(int i=0; i<n; i++) all[i]=a[i]; for(int i=0; i<m; i++) all[n+i]=b[i];
    qsort(all, n+m, sizeof(int), cmp);
    for(int i=0; i<n+m; i++) printf("%d ", all[i]);
    printf("\n");
    return 0;
}
