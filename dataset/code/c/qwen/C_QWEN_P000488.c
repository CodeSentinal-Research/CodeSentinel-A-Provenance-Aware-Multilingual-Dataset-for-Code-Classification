#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[200][200], heights[200];
    for(int i=0; i<c; i++) heights[i]=0;
    int max_area=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &mat[i][j]);
            heights[j] = mat[i][j] ? heights[j]+1 : 0;
        }
        int stack[200], top=-1;
        for(int j=0; j<=c; j++) {
            int h = (j==c) ? 0 : heights[j];
            while(top>=0 && heights[stack[top]]>h) {
                int height = heights[stack[top--]];
                int width = (top==-1) ? j : j-stack[top]-1;
                int area = height*width;
                if(area>max_area) max_area=area;
            }
            stack[++top]=j;
        }
    }
    printf("%d\n", max_area);
    return 0;
}
