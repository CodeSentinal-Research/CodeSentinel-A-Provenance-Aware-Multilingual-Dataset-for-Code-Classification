#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    int *x=(int*)a, *y=(int*)b;
    int d1=abs(x[0])-abs(x[1]), d2=abs(y[0])-abs(y[1]);
    return d1-d2;
}
int main() {
    int rows, cols, rc, cc; scanf("%d %d %d %d", &rows, &cols, &rc, &cc);
    int cells[rows*cols][2], idx=0;
    for(int i=0; i<rows; i++) for(int j=0; j<cols; j++) { cells[idx][0]=i; cells[idx][1]=j; idx++; }
    // Sort by distance
    for(int i=0; i<rows*cols; i++) for(int j=i+1; j<rows*cols; j++) {
        int d1=abs(cells[i][0]-rc)+abs(cells[i][1]-cc);
        int d2=abs(cells[j][0]-rc)+abs(cells[j][1]-cc);
        if(d1>d2) { int t=cells[i][0]; cells[i][0]=cells[j][0]; cells[j][0]=t; t=cells[i][1]; cells[i][1]=cells[j][1]; cells[j][1]=t; }
    }
    for(int i=0; i<rows*cols; i++) printf("[%d,%d] ", cells[i][0], cells[i][1]);
    printf("\n");
    return 0;
}
