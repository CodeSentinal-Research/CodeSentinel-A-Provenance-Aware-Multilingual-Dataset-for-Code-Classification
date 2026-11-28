#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    int grid[r][c]; for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    int height[c], max_area = 0;
    for(int i=0; i<c; i++) height[i] = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) height[j] = grid[i][j] ? height[j] + 1 : 0;
        int stack[c], top = -1;
        for(int j=0; j<=c; j++) {
            int h = j == c ? 0 : height[j];
            while(top >= 0 && height[stack[top]] > h) {
                int hgt = height[stack[top--]];
                int w = top == -1 ? j : j - stack[top] - 1;
                if(hgt * w > max_area) max_area = hgt * w;
            }
            stack[++top] = j;
        }
    }
    printf("%d\n", max_area);
    return 0;
}
