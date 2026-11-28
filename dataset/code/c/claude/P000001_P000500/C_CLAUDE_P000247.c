#include<stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c],B[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&B[i][j]);for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(A[i][j]!=B[i][j]){printf("Not Identical\n");return 0;}printf("Identical\n");}
