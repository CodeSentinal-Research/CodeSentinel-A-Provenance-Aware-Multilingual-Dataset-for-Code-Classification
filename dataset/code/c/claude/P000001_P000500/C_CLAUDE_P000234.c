#include<stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);int R[r],C[c];for(int i=0;i<r;i++)R[i]=0;for(int j=0;j<c;j++)C[j]=0;for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(A[i][j]){R[i]=1;C[j]=1;}for(int i=0;i<r;i++){for(int j=0;j<c;j++)printf("%d%c",(R[i]||C[j])?1:A[i][j],j<c-1?' ':\'\\n');}}
