#include<stdio.h>
int main(){int r,c,t;scanf("%d %d %d",&r,&c,&t);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);int i=0,j=c-1;while(i<r&&j>=0){if(A[i][j]==t){printf("%d %d\n",i,j);return 0;}else if(A[i][j]>t)j--;else i++;}printf("-1 -1\n");}
