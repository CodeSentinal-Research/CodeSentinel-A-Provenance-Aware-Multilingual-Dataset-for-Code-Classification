#include <stdio.h>
#include <stdlib.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], height[c], max_area=0;
    for(int i=0; i<c; i++) height[i] = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); height[j] = mat[i][j] ? height[j]+1 : 0; }
        for(int j=0; j<c; j++) {
            int min_h = height[j];
            for(int k=j; k<c; k++) {
                if(height[k] < min_h) min_h = height[k];
                int area = min_h * (k - j + 1);
                if(area > max_area) max_area = area;
            }
        }
    }
    printf("%d\n", max_area);
    return 0;
}
