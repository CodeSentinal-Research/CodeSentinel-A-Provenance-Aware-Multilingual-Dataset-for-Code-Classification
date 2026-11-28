#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n], sym = 1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<n && sym; i++) for(int j=0; j<n && sym; j++) if(mat[i][j] != mat[j][i]) sym = 0;
    printf("%s\n", sym ? "Symmetric" : "Not Symmetric");
    return 0;
}
