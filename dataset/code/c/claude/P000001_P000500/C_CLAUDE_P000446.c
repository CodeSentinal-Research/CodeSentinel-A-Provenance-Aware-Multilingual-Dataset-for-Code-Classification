#include<stdio.h>
int main(){int r,c,x;scanf("%d %d %d",&r,&c,&x);int mat[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&mat[i][j]);int row=0,col=c-1;while(row<r&&col>=0){if(mat[row][col]==x){printf("Found\n");return 0;}else if(mat[row][col]>x)col--;else row++;}printf("Not Found\n");}
