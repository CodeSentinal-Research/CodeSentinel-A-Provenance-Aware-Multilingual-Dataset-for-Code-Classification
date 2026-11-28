#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<n; i++) for(int j=i; j<n; j++) { int t=mat[i][j]; mat[i][j]=mat[j][i]; mat[j][i]=t; }
    for(int i=0; i<n; i++) for(int j=0; j<n/2; j++) { int t=mat[i][j]; mat[i][j]=mat[i][n-1-j]; mat[i][n-1-j]=t; }
    for(int i=0; i<n; i++) { for(int j=0; j<n; j++) printf("%d%c", mat[i][j], j==n-1?'\n':' '); }
    return 0;
}
