#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int top=0, bottom=r-1, left=0, right=c-1;
    while(top<bottom && left<right) {
        int prev = mat[top+1][left];
        for(int i=left; i<=right; i++) { int t=mat[top][i]; mat[top][i]=prev; prev=t; } top++;
        for(int i=top; i<=bottom; i++) { int t=mat[i][right]; mat[i][right]=prev; prev=t; } right--;
        for(int i=right; i>=left; i--) { int t=mat[bottom][i]; mat[bottom][i]=prev; prev=t; } bottom--;
        for(int i=bottom; i>=top; i--) { int t=mat[i][left]; mat[i][left]=prev; prev=t; } left++;
    }
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) printf("%d%c", mat[i][j], j==c-1?'\n':' ');
    return 0;
}
