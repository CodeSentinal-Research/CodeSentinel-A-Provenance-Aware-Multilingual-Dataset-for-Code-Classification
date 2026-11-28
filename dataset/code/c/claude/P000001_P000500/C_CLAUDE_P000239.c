#include<stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);int first=1;for(int j=0;j<c;j++){if(!first)printf(" ");printf("%d",A[0][j]);first=0;}for(int i=1;i<r-1;i++){printf(" %d",A[i][0]);printf(" %d",A[i][c-1]);}if(r>1)for(int j=0;j<c;j++)printf(" %d",A[r-1][j]);printf("\n");}
