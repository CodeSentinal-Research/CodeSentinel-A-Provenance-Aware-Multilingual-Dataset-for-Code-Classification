#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], row[r]={0}, col[c]={0};
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); if(mat[i][j]==1) { row[i]=1; col[j]=1; } }
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(row[i] || col[j]) mat[i][j] = 1;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) printf("%d%c", mat[i][j], j==c-1?'\n':' ');
    return 0;
}
