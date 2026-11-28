#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], min=1000000000, max=-1000000000;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); if(mat[i][j]<min) min=mat[i][j]; if(mat[i][j]>max) max=mat[i][j]; }
    int desired = (r*c)/2 + 1;
    while(min < max) {
        int mid = min + (max-min)/2, count=0;
        for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(mat[i][j] <= mid) count++;
        if(count < desired) min = mid + 1; else max = mid;
    }
    printf("%d\n", min);
    return 0;
}
