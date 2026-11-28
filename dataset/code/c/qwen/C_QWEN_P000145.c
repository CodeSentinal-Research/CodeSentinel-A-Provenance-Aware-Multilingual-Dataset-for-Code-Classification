#include <stdio.h>
int main() {
    int r, c, target; scanf("%d %d %d", &r, &c, &target);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int l=0, right=r*c-1;
    while(l<=right) {
        int mid = l + (right-l)/2;
        int val = mat[mid/c][mid%c];
        if(val == target) { printf("Found\n"); return 0; }
        if(val < target) l = mid + 1; else right = mid - 1;
    }
    printf("Not Found\n");
    return 0;
}
