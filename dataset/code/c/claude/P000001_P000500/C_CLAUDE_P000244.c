#include<stdio.h>
int max2(int a,int b){return a>b?a:b;}
int main(){int r,c;scanf("%d %d",&r,&c);int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&A[i][j]);for(int i=1;i<r;i++)for(int j=0;j<c;j++){int best=A[i-1][j];if(j>0)best=max2(best,A[i-1][j-1]);if(j<c-1)best=max2(best,A[i-1][j+1]);A[i][j]+=best;}int mx=A[r-1][0];for(int j=1;j<c;j++)if(A[r-1][j]>mx)mx=A[r-1][j];printf("%d\n",mx);}
