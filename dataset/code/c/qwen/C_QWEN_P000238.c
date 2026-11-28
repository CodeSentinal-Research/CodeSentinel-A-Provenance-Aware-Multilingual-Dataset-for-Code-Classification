#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n], prod[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        prod[i][j] = 0;
        for(int k=0; k<n; k++) prod[i][j] += mat[i][k] * mat[j][k];
    }
    int orth = 1;
    for(int i=0; i<n && orth; i++) for(int j=0; j<n && orth; j++) if(prod[i][j] != (i==j ? 1 : 0)) orth = 0;
    printf("%s\n", orth ? "Yes" : "No");
    return 0;
}
