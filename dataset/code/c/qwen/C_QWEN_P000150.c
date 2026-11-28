#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], all[r*c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); all[i*c+j] = mat[i][j]; }
    qsort(all, r*c, sizeof(int), cmp);
    int idx = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) printf("%d%c", all[idx++], j==c-1?'\n':' ');
    return 0;
}
