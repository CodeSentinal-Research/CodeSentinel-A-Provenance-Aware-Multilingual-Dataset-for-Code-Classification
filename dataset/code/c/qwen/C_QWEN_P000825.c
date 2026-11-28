#include <stdio.h>
int main() {
    int n, m, target; scanf("%d%d%d", &n, &m, &target);
    int mat[n][m]; for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &mat[i][j]);
    int i=0, j=m-1, found=0;
    while(i<n && j>=0) { if(mat[i][j]==target) { found=1; break; } else if(mat[i][j]>target) j--; else i++; }
    printf("%s\n", found?"true":"false");
    return 0;
}
