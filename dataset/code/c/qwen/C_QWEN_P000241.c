#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<n; i++) {
        int min_val = mat[i][0], min_col = 0;
        for(int j=1; j<n; j++) if(mat[i][j] < min_val) { min_val = mat[i][j]; min_col = j; }
        int is_max = 1;
        for(int k=0; k<n; k++) if(mat[k][min_col] > min_val) { is_max = 0; break; }
        if(is_max) { printf("%d\n", min_val); return 0; }
    }
    printf("No Saddle Point\n");
    return 0;
}
