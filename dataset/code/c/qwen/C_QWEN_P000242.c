#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n], zeros=0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { scanf("%d", &mat[i][j]); if(mat[i][j]==0) zeros++; }
    printf("%d\n", zeros);
    return 0;
}
