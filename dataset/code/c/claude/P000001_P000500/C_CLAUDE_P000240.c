#include<stdio.h>
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);long long s=0;for(int j=0;j<c;j++)s+=A[0][j];for(int j=0;j<c;j++)s+=A[r-1][j];for(int i=1;i<r-1;i++)s+=A[i][0]+A[i][c-1];printf("%lld\n",s);}
