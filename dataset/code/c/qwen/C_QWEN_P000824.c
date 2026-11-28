#include <stdio.h>
int main() {
    int n, m, target; scanf("%d%d%d", &n, &m, &target);
    int mat[n][m]; for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &mat[i][j]);
    int l=0, r=n*m-1, found=0;
    while(l<=r) { int mid=l+(r-l)/2; int val=mat[mid/m][mid%m]; if(val==target) { found=1; break; } else if(val<target) l=mid+1; else r=mid-1; }
    printf("%s\n", found?"true":"false");
    return 0;
}
