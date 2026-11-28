#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int mat[n][n], all[n*n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { scanf("%d", &mat[i][j]); all[i*n+j] = mat[i][j]; }
    qsort(all, n*n, sizeof(int), cmp);
    for(int i=0; i<n*n; i++) printf("%d%c", all[i], (i+1)%n==0?'\n':' ');
    return 0;
}
