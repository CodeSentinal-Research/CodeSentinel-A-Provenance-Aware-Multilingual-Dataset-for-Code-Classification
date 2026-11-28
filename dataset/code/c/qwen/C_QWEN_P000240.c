#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], sum=0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    for(int j=0; j<c; j++) sum += mat[0][j] + mat[r-1][j];
    for(int i=1; i<r-1; i++) sum += mat[i][0] + mat[i][c-1];
    if(r==1 || c==1) sum = 0; // avoid double counting if 1 row/col, but constraints say >=1. Simplified:
    sum = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(i==0 || i==r-1 || j==0 || j==c-1) sum += mat[i][j];
    printf("%d\n", sum);
    return 0;
}
