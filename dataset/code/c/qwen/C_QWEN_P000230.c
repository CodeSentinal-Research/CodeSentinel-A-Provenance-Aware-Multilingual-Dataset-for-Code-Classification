#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], count[100001]={0};
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); count[mat[i][j]]++; }
    int first = 1;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(count[mat[i][j]] == r) { if(!first) printf(" "); printf("%d", mat[i][j]); count[mat[i][j]]=0; first=0; }
    printf("\n");
    return 0;
}
