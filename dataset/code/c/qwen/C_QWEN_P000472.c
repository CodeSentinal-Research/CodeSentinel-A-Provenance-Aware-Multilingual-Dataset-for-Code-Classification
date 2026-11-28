#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[50][50];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int peak = mat[0][0];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        int is_peak = 1;
        if(i>0 && mat[i-1][j]>=mat[i][j]) is_peak=0;
        if(i<r-1 && mat[i+1][j]>=mat[i][j]) is_peak=0;
        if(j>0 && mat[i][j-1]>=mat[i][j]) is_peak=0;
        if(j<c-1 && mat[i][j+1]>=mat[i][j]) is_peak=0;
        if(is_peak && mat[i][j]>peak) peak=mat[i][j];
    }
    printf("%d\n", peak);
    return 0;
}
