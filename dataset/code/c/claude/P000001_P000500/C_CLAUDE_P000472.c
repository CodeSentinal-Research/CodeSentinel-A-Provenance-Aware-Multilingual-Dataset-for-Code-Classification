#include<stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int mat[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&mat[i][j]);for(int i=0;i<r;i++)for(int j=0;j<c;j++){int v=mat[i][j];if((i==0||v>mat[i-1][j])&&(i==r-1||v>mat[i+1][j])&&(j==0||v>mat[i][j-1])&&(j==c-1||v>mat[i][j+1])){printf("%d\n",v);return 0;}}}
