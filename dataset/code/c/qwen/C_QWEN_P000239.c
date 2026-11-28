#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int first = 1;
    for(int j=0; j<c; j++) { if(!first) printf(" "); printf("%d", mat[0][j]); first=0; }
    for(int i=1; i<r; i++) { if(!first) printf(" "); printf("%d", mat[i][c-1]); first=0; }
    if(r>1) for(int j=c-2; j>=0; j--) { if(!first) printf(" "); printf("%d", mat[r-1][j]); first=0; }
    if(c>1) for(int i=r-2; i>0; i--) { if(!first) printf(" "); printf("%d", mat[i][0]); first=0; }
    printf("\n");
    return 0;
}
