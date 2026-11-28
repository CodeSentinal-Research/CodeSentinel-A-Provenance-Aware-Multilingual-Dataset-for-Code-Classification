#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int row[r], col[c];
    for(int i=0; i<r; i++) row[i] = 0;
    for(int i=0; i<c; i++) col[i] = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(mat[i][j] == 0) { row[i] = 1; col[j] = 1; }
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(row[i] || col[j]) mat[i][j] = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) printf("%d%c", mat[i][j], j==c-1?'\n':' ');
    return 0;
}
