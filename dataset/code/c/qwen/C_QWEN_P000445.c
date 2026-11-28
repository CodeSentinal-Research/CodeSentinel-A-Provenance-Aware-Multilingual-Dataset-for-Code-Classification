#include <stdio.h>
int main() {
    int r, c, target; scanf("%d %d %d", &r, &c, &target);
    int mat[100][100];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int l=0, right=r*c-1, found=0;
    while(l<=right) {
        int mid = l+(right-l)/2;
        int val = mat[mid/c][mid%c];
        if(val==target) { found=1; break; }
        if(val<target) l=mid+1; else right=mid-1;
    }
    printf("%s\n", found ? "Found" : "Not Found");
    return 0;
}
