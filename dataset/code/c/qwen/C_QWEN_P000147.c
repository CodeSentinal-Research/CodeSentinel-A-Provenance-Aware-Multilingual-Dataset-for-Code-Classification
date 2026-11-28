#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int mat[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
    int first = 1;
    for(int i=0; i<n; i++) { if(!first) printf(" "); printf("%d", mat[i][i]); first=0; }
    for(int i=0; i<n; i++) { if(!first) printf(" "); printf("%d", mat[i][n-1-i]); first=0; }
    printf("\n");
    return 0;
}
