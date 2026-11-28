#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int top=0, bottom=r-1, left=0, right=c-1, first=1;
    while(top<=bottom && left<=right) {
        for(int i=left; i<=right; i++) { if(!first) printf(" "); printf("%d", mat[top][i]); first=0; } top++;
        for(int i=top; i<=bottom; i++) { if(!first) printf(" "); printf("%d", mat[i][right]); first=0; } right--;
        if(top<=bottom) { for(int i=right; i>=left; i--) { if(!first) printf(" "); printf("%d", mat[bottom][i]); first=0; } bottom--; }
        if(left<=right) { for(int i=bottom; i>=top; i--) { if(!first) printf(" "); printf("%d", mat[i][left]); first=0; } left++; }
    }
    printf("\n");
    return 0;
}
