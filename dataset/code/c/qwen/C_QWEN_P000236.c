#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n], max_diff = -1000000000;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    for(int a=0; a<n-1; a++) for(int b=0; b<n-1; b++) {
        int min_val = mat[a][b];
        for(int c=a+1; c<n; c++) for(int d=b+1; d<n; d++) {
            if(mat[c][d] - min_val > max_diff) max_diff = mat[c][d] - min_val;
        }
    }
    printf("%d\n", max_diff);
    return 0;
}
