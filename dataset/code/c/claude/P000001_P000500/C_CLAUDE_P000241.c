#include<stdio.h>
int main(){int n;scanf("%d",&n);int A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&A[i][j]);for(int i=0;i<n;i++){int mn=A[i][0],jm=0;for(int j=1;j<n;j++)if(A[i][j]<mn){mn=A[i][j];jm=j;}int ok=1;for(int k=0;k<n;k++)if(A[k][jm]<mn){ok=0;break;}if(ok){printf("%d %d %d\n",i,jm,mn);return 0;}}printf("No Saddle Point\n");}
