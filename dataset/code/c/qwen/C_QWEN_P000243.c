#include <stdio.h>
int main() {
    int r, c, target; scanf("%d %d %d", &r, &c, &target);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int i=0, j=c-1, found=0;
    while(i<r && j>=0) {
        if(mat[i][j] == target) { found=1; break; }
        else if(mat[i][j] > target) j--;
        else i++;
    }
    printf("%s\n", found ? "Found" : "Not Found");
    return 0;
}
